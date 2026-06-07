const int segA = ___;
const int segB = ___;
const int segC = ___;
const int segD = ___;
const int segE = ___;
const int segF = ___;
const int segG = ___;

const int buttonPin = ___;

int currentValue = 0;
bool lastButtonState = HIGH;

byte digitPatterns[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void displayDigit(int value) {
  digitalWrite(segA, digitPatterns[value][0]);
  digitalWrite(segB, digitPatterns[value][1]);
  digitalWrite(segC, digitPatterns[value][2]);
  digitalWrite(segD, digitPatterns[value][3]);
  digitalWrite(segE, digitPatterns[value][4]);
  digitalWrite(segF, digitPatterns[value][5]);
  digitalWrite(segG, digitPatterns[value][6]);
}

void setup() {
  Serial.begin(115200);

  pinMode(segA, ______);
  pinMode(segB, ______);
  pinMode(segC, ______);
  pinMode(segD, ______);
  pinMode(segE, ______);
  pinMode(segF, ______);
  pinMode(segG, ______);

  pinMode(buttonPin, ____________);

  displayDigit(currentValue);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  Serial.print("Button State: ");
  Serial.println(buttonState);
  Serial.print("Current Value: ");
  Serial.println(currentValue);

  if (buttonState == ______ && lastButtonState == ______) {
    currentValue = _______________________;
    displayDigit(currentValue);
  }

  lastButtonState = buttonState;
  delay(50);
}