enum GameState {
  ST_IDLE = 0,
  ____________________,
  ____________________,
  ____________________,
  ____________________
};

const int LED_COUNT = ______;
const int ledPins[LED_COUNT] = {______, ______, ______, ______, ______, ______, ______};
const int TARGET_INDEX = ______;
const int BUTTON_PIN = ______;

const unsigned long MOVE_DELAY_MS = ______;
const unsigned long WIN_BLINK_DELAY_MS = ______;
const unsigned long DEBOUNCE_MS = ______;

GameState state = ____________________;
int pos = ______;

unsigned long lastMoveTime = 0;
unsigned long lastBlinkTime = 0;
unsigned long lastButtonTime = 0;
bool blinkState = false;

int shownIndex = -1;  // which LED ledShowIndex() last lit; used by reportStatus()


void ledsAllOff() {
  for (int i = 0; i < LED_COUNT; i++) {
    ______________________________________;
  }
}

void ledsAllOn() {
  for (int i = 0; i < LED_COUNT; i++) {
    ______________________________________;
  }
}

void ledShowIndex(int idx) {
  // Drive each pin straight to its final level. (Doing ledsAllOff() first would blink
  // the target LED LOW->HIGH on every loop, a flicker the pin reads can sample.)
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], (i == idx) ? HIGH : LOW);
  }
  shownIndex = idx;
}

void showIdlePattern() {
  ledsAllOff();
  ______________________________________;
}

bool buttonWasPressed() {
  if (digitalRead(____________________) == ______) {
    unsigned long now = millis();
    if (now - lastButtonTime > ____________________) {
      lastButtonTime = now;

      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(5);
      }
      return true;
    }
  }
  return false;
}

void resetGame() {
  state = ____________________;
  pos = ______;
  blinkState = false;
  ______________________________________;
}

void reportStatus() {
  static unsigned long lastReport = 0;
  unsigned long now = millis();
  if (now - lastReport < 50) return;
  lastReport = now;

  switch (state) {
    case ST_IDLE:
      Serial.println("IDLE  | center light on -- press the button to start");
      break;
    case ST_MOVE_R:
      Serial.print("POS: ");
      Serial.print(shownIndex);
      Serial.println("  | light moving right");
      break;
    case ST_MOVE_L:
      Serial.print("POS: ");
      Serial.print(shownIndex);
      Serial.println("  | light moving left");
      break;
    case ST_WIN:
      Serial.println("WIN!  | stopped on the center -- all lights flashing");
      break;
    case ST_LOSE:
      Serial.print("LOSE  | missed the center -- light frozen at POS ");
      Serial.print(shownIndex);
      Serial.println(", press to retry");
      break;
  }
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < LED_COUNT; i++) {
    ________________________________;
    ________________________________;
  }

  pinMode(____________________, INPUT_PULLUP);

  resetGame();
  Serial.println();
  Serial.println("====== Cyclone Arcade Game ======");
  Serial.println("Stop the moving light on the center to score!");
}

void loop() {
  unsigned long now = millis();

  switch (state) {
    case ST_IDLE:
      ______________________________________;
      if (buttonWasPressed()) {
        pos = ______;
        ledShowIndex(pos);
        state = ____________________;
        lastMoveTime = now;
      }
      break;

    case ST_MOVE_R:
      ______________________________________;

      if (buttonWasPressed()) {
        state = (pos == ____________________) ? ____________________ : ____________________;
        lastBlinkTime = now;
        blinkState = false;
        break;
      }

      if (now - lastMoveTime >=  ____________________) {
        lastMoveTime = now;
        if (pos >= ____________________) {
          state =  ____________________;
        } else {
         ____________________;
        }
      }
      break;

    case ST_MOVE_L:
      ______________________________________;

      if (buttonWasPressed()) {
        state = (pos ==  ____________________) ?  ____________________:  ____________________;
        lastBlinkTime = now;
        blinkState = false;
        break;
      }

      if (now - lastMoveTime >= ____________________) {
        lastMoveTime = now;
        if (pos <= ______) {
          state =  ____________________;
        } else {
          ____________________;
        }
      }
      break;

    case ST_WIN:
      if (now - lastBlinkTime >=  ____________________) {
        lastBlinkTime = now;
        blinkState = !blinkState;

        if (blinkState) {
          ____________________;
        } else {
           ____________________;
        }
      }

      if (buttonWasPressed()) {
        ____________________;
      }
      break;

    case ST_LOSE:
      ______________________________________;
      if (buttonWasPressed()) {
         ____________________;
      }
      break;

    default:
      ____________________;
      break;
  }

  reportStatus();  // report AFTER the LEDs have been updated, so serial matches hardware
}
