/*
  Based on:
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch gateRadio = RCSwitch();

#define relayPin 13

int gateKey = 192;
int debounceDelay = 1000;
int relayOnTime = 200;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  gateRadio.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (gateRadio.available()) {
    Serial.println("testing");
    if (gateRadio.getReceivedValue() == gateKey) {
      digitalWrite(relayPin, HIGH);
      Serial.println("ok!");
      delay(relayOnTime);
      digitalWrite(relayPin, LOW);
      delay(debounceDelay);
    }
    else {Serial.println("nok");}
    gateRadio.resetAvailable();
  }
}
