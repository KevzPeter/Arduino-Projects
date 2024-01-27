#include <Servo.h>

Servo servo1;

int SERVO = 11;
int LED = 10;
int TRIG = 9;
int ECHO = 8;
int BUZZER = 12;
const int DELAY = 25;
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
}

void loop()
{
    // put your main code here, to run repeatedly:
    for (int i = 0; i <= 180; i++)
    {
        servo1.write(i);
        controlLED();
        delay(DELAY);
    }
    for (int i = 180; i >= 0; i--)
    {
        servo1.write(i);
        controlLED();
        delay(DELAY);
    }
}

void controlLED()
{
    int distance = measureDistance();
    if (distance < 60)
    {
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
        Serial.print("Object detected at: ");
        Serial.print(distance);
        Serial.print(" cm");
        Serial.println();
    }
    else
    {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
    }
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