# Lab2 Testing

This document describes what the `lab2_tests.yaml` Wokwi scenario verifies. The
firmware is a **"Cyclone" arcade game**: 7 LEDs on GPIO 0–6, a light sweeps back
and forth, and you press the button (GPIO 7) trying to stop it on the **center
LED (index 3 = the target)**. The test drives the whole game through one boot and
verifies both the serial output and the physical pin states agree at every stage.

## What each section verifies

### 1. Boot → IDLE (the resting state)
- Waits for the `IDLE` serial line (confirms the chip booted and serial is routed).
- Checks the button pin reads HIGH (`esp:7 == 1`) — i.e. `INPUT_PULLUP` is working and it's unpressed.
- Checks only the center LED (GPIO 3) is lit, all other 6 are off. This is `showIdlePattern()`.

### 2. Button-press start
- Presses the button and confirms `esp:7` goes LOW — the press is electrically seen.
- Releases it. This is the test that the button itself works (the thing that was broken via the missing serial wiring).

### 3. Rightward sweep, GPIO 0 → 6
- For each index 0–6: waits for `POS: N` on serial, then asserts exactly one LED is HIGH and the other six are LOW. This is the core GPIO test — every output pin is exercised and proven independently drivable, and it proves the `ledShowIndex()` "one light moving" behavior.
- At index 0 it also re-checks `esp:7 == 1` (button released cleanly).

### 4. Bounce + WIN
- After hitting the right edge (index 6), the firmware reverses (`ST_MOVE_L`). The test consumes the leftward `POS: 5`, `POS: 4`, `POS: 3` lines — this exercises the leftward direction too.
- Stops on `POS: 3` (the center) → presses → waits for `WIN`.
- Then samples 270 ms later and asserts all 7 LEDs are HIGH — verifying the win-blink "all flashing" phase (`ledsAllOn()`).

### 5. Reset WIN → IDLE
- Presses again, waits for `IDLE`, confirms it's back to center-only.

### 6. LOSE path
- Starts again, stops off-center at `POS: 2` → waits for `LOSE`.
- Asserts the LED is frozen at index 2 (`esp:2 == 1`) and is not the center (`esp:3 == 0`) — verifying the lose branch (`pos != TARGET_INDEX`) holds the light in place.

### 7. Reset LOSE → IDLE
- Final press → `IDLE` → center back on, index 2 off.

## In short, the test asserts:

| Concern | How it's verified |
|---|---|
| Chip boots & serial routed | `wait-serial: "IDLE"` ever fires |
| Button input (GPIO 7, pullup + press) | `esp:7` reads 1 idle, 0 pressed |
| All 7 LED outputs work individually | one-hot pin sweep across `POS: 0..6` |
| State machine: IDLE→MOVE_R→MOVE_L | directional `POS:` sequence both ways |
| WIN logic (stop on center) | `WIN` line + all-on blink |
| LOSE logic (stop off-center) | `LOSE` line + frozen at lost index |
| Reset from both WIN and LOSE | returns to center-only IDLE |
| Serial ↔ hardware agreement | every `wait-serial` paired with `expect-pin` |

So it's an end-to-end functional test of the game: input, all outputs, the full
state machine in both directions, and win/lose/reset — gated on the serial log
staying consistent with the actual pin levels.
