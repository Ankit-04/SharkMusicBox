#include <IRremote.h>

const byte recPin = 3;
IRrecv irrecv(recPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  attachInterrupt(digitalPinToInterrupt(recPin), songSelect, CHANGE);

}

void loop() {
}
void songSelect() {
  if (irrecv.decode(&results))
  {
    switch (results.value) {
      case 0xFF30CF: //Keypad button "1"
        babysharkdodo();
        break;
      case 0xFF18E7: //Keypad button "2"
        jaws();
        break;
      case 0xFF7A85: //Keypad button "3"
        nevergonnagiveyouup();
        break;
    }
    irrecv.resume();
  }
}

void babysharkdodo() {
  Serial.println("baby");
}

void jaws() {
  Serial.println("dundun");
}
void nevergonnagiveyouup() {
  Serial.println("best song ever");
}
