/*
    Author: Kevin Peter
    Circuit Diagram: https://wokwi.com/projects/388105596571181057
*/

#include <Servo.h>

Servo servo1;

int SERVO = 11;
int LED = 10;
int TRIG = 9;
int ECHO = 8;
int BUZZER = 12;
const int DELAY = 25;
const int ALARM_DISTANCE = 10;

void setup()
{
    // put your setup code here, to run once:
    pinMode(LED, OUTPUT);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(BUZZER, OUTPUT);
    Serial.begin(9600);
    servo1.attach(SERVO);
    servo1.write(0);
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
    Serial.println("Radar Start");
}

void loop()
{
    // put your main code here, to run repeatedly:
    for (int i = 0; i <= 180; i++)
    {
        servo1.write(i);
        controlLEDBuzzer(i);
        delay(DELAY);
    }
    for (int i = 180; i >= 0; i--)
    {
        servo1.write(i);
        controlLEDBuzzer(i);
        delay(DELAY);
    }
}

void controlLEDBuzzer(int pos)
{
    int distance = measureDistance();
    if (distance < ALARM_DISTANCE)
    {
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
    }
    Serial.print(pos);
    Serial.print(",");
    Serial.println(distance);
}

int measureDistance()
{
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    float duration = pulseIn(ECHO, HIGH);
    float distance = (duration * .0343) / 2;
    return floor(distance);
}