/*
  Press the button once to turn on the LED and
  press the button again to turn off the LED
  (Can be repeated)
*/

int pushButton = 3;
int ledPin = 12;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;

void setup() {
  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(pushButton);
  if (last != current) {
    delay(5);
    current = digitalRead(pushButton);
  }
  return current;
}

void loop() {
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {
    ledOn = !ledOn;
  }
  lastButton = currentButton;
  digitalWrite(ledPin, ledOn);
}
