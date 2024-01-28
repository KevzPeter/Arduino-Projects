/*
  Arduino Christmas Songs

  Based on a project and code by Dipto Pratyaksa, updated on 31/3/13

  Modified for Christmas by Joshi, on Dec 17th, 2017.

  Adapted by Kevin Peter (github.com/KevzPeter)
*/

#include "pitches.h"

#define BUZZER 11
#define GREEN_LED 8
#define RED_LED 9

// Jingle Bells

int melody[] = {
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
    NOTE_E5,
    NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_D5, NOTE_G5};

int tempo[] = {
    8, 8, 4,
    8, 8, 4,
    8, 8, 8, 8,
    2,
    8, 8, 8, 8,
    8, 8, 8, 16, 16,
    8, 8, 8, 8,
    4, 4};

// We wish you a merry Christmas

int wish_melody[] = {
    NOTE_B3,
    NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
    NOTE_D4, NOTE_D4, NOTE_D4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_E4, NOTE_E4, NOTE_E4,
    NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
    NOTE_D4, NOTE_G4, NOTE_E4,
    NOTE_F4};

int wish_tempo[] = {
    4,
    4, 8, 8, 8, 8,
    4, 4, 4,
    4, 8, 8, 8, 8,
    4, 4, 4,
    4, 8, 8, 8, 8,
    4, 4, 8, 8,
    4, 4, 4,
    2};

void setup(void)
{
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

void loop()
{
    // Input the song you wish to play !
    sing(1);
}

void sing(int song)
{
    if (song == 2)
    {
        Serial.println(" 'We wish you a Merry Christmas'");
        int size = sizeof(wish_melody) / sizeof(int);
        playNotes(wish_melody, wish_tempo, size);
    }
    else
    {

        Serial.println(" 'Jingle Bells'");
        int size = sizeof(melody) / sizeof(int);
        playNotes(melody, tempo, size);
    }
}

void playNotes(int melody[], int tempo[], int size)
{
    int prevNote = NULL;
    int currentLED = RED_LED;
    for (int thisNote = 0; thisNote < size; thisNote++)
    {
        // to calculate the note duration, take one second
        // divided by the note type.
        // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / tempo[thisNote];
        if (prevNote != NULL && prevNote != melody[thisNote])
        {
            currentLED = currentLED == RED_LED ? GREEN_LED : RED_LED;
        }
        digitalWrite(currentLED, HIGH);
        buzz(BUZZER, melody[thisNote], noteDuration);
        digitalWrite(currentLED, LOW);
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        // stop the tone playing:
        buzz(BUZZER, 0, noteDuration);
        prevNote = melody[thisNote];
    }
}

void buzz(int targetPin, long frequency, long length)
{
    long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
    //// 1 second's worth of microseconds, divided by the frequency, then split in half since
    //// there are two phases to each cycle
    long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
    //// multiply frequency, which is really cycles per second, by the number of seconds to
    //// get the total number of cycles to produce
    for (long i = 0; i < numCycles; i++)
    {                                  // for the calculated length of time...
        digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
        delayMicroseconds(delayValue); // wait for the calculated delay value
        digitalWrite(targetPin, LOW);  // write the buzzer pin low to pull back the diaphram
        delayMicroseconds(delayValue); // wait again or the calculated delay value
    }
}