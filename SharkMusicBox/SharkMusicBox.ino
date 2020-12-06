#include <IRremote.h>
#include "pitches.h"

const byte buzzerPin = 8;
const byte recPin = 11;
IRrecv irrecv(recPin);
decode_results results;



void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {
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
  int melody[] =
  {
    NOTE_D4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_G4,
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_FS4
  }  ;
  int noteDurations[] = {2, 2, 4, 4, 4, 8, 4, 8, 4, 4, 4, 4, 4, 4, 8, 4, 8, 4, 4, 4, 4, 4, 4, 8, 4, 8, 4, 4, 4, 1.5};

  for (int thisNote = 0; thisNote < 30; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }

}

void jaws() {
  Serial.println("dundun");
    int melody[] =
  {
    NOTE_E3, NOTE_F3, 0, 0, NOTE_E3, NOTE_F3, NOTE_E3, 0, 0, 0,
    NOTE_E3, NOTE_F3, 0, NOTE_E3, NOTE_F3, 0, NOTE_E3, NOTE_F3, 0,
    NOTE_E3, NOTE_F3,NOTE_E3, NOTE_F3,NOTE_E3, NOTE_F3,NOTE_E3, NOTE_F3,NOTE_E3, NOTE_F3,
  }  ;
  int noteDurations[] = {2, 4, 4, 1, 2, 2, 4, 4, 2, 1, 2, 4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4};

  for (int thisNote = 0; thisNote < 29; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }

}
void nevergonnagiveyouup() {
  Serial.println("best song ever");
}
