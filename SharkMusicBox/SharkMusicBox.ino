#include <IRremote.h>
#include "pitches.h"

const byte buzzerPin = 8;
const byte recPin = 11;
IRrecv irrecv(recPin);
decode_results results;

int melody = {};

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
        //jaws();
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

/*void jaws() {
  Serial.println("dundun");
  int melody[] =
  {
    NOTE_E3, NOTE_F3, 0, 0, NOTE_E3, NOTE_F3, NOTE_E3, 0, 0, 0,
    NOTE_E3, NOTE_F3, 0, NOTE_E3, NOTE_F3, 0, NOTE_E3, NOTE_F3, 0,
    NOTE_E3, NOTE_F3, NOTE_E3, NOTE_F3, NOTE_E3, NOTE_F3, NOTE_E3, NOTE_F3, NOTE_E3, NOTE_F3,
  }  ;
  int noteDurations[] = {2, 4, 4, 1, 2, 2, 4, 4, 2, 1, 2, 4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4};

  for (int thisNote = 0; thisNote < 29; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }

  }*/
void nevergonnagiveyouup() {
  int melody[] =
  {
    NOTE_A4, NOTE_B4, NOTE_D4, NOTE_B4, NOTE_FS5, NOTE_FS5, NOTE_E5,
    NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_A4, NOTE_E5, NOTE_E5, NOTE_D5,
    NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_A4, NOTE_A4, NOTE_E5, NOTE_D5,
    NOTE_A4, NOTE_B4, NOTE_D4, NOTE_B4, NOTE_FS5, NOTE_FS5, NOTE_E5,
    NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_A4, NOTE_A5, NOTE_CS5, NOTE_D5,
    NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_E5, NOTE_D5
  };
  int noteDurations[] =
  {
    6, 7.5, 8, 8, 3, 3, 1.5,
    8, 8, 8, 8, 4, 4, 2.5, 
    8, 4, 8, 8, 8, 8,
    2, 4, 2, 2, 4, 2, 1.5,
    8, 8, 8, 8, 3, 3, 1.25,
    8, 8, 8, 8, 2, 4, 3.5,
    4, 3, 6, 8, 8, 7.5,
    2, 4, 3, 8, 3, 4, 2, 1.5
  };

  for (int thisNote = 0; thisNote < 55; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}
