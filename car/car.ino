#include <AFMotor.h>
#include <NewPing.h>

#define DISTANCE_SENSOR_ECHO A0
#define DISTANCE_SENSOR_TRIG A1
#define LED A2
#define MAX_DISTANCE 20

AF_DCMotor frontRight(1); // M1
AF_DCMotor frontLeft(2);  // M2
AF_DCMotor rearLeft(3);   // M3
AF_DCMotor rearRight(4);  // M4

NewPing sonar(DISTANCE_SENSOR_TRIG, DISTANCE_SENSOR_ECHO, MAX_DISTANCE); // sensor function

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    frontRight.setSpeed(50);
    frontRight.run(FORWARD);
    frontLeft.setSpeed(50);
    frontLeft.run(FORWARD);
    rearLeft.setSpeed(50);
    rearLeft.run(RELEASE);
    rearRight.setSpeed(50);
    rearRight.run(RELEASE);
    pinMode(LED, OUTPUT);
    analogWrite(LED, 255);
    pinMode(DISTANCE_SENSOR_ECHO, INPUT);
    pinMode(DISTANCE_SENSOR_TRIG, OUTPUT);
    Serial.println("Ready to roll!");
}

void loop()
{
    int data = 0;
    if (Serial.available())
    {
        data = Serial.read();
        Serial.print("Data from Bluetooth device: ");
        Serial.print(data);
        Serial.println();
    }
    int distance = readPing();
    if (distance >= MAX_DISTANCE)
    {
        if (data == 'A')
        {
            moveForward();
        }
        else if (data == 'B')
        {
            moveBackward();
        }
        else if (data == 'C')
        {
            turnLeft();
        }
        else
        {
            turnRight();
        }
    }
    else
    {
        stopMoving();
    }
    delay(100);
}

int readPing()
{
    delay(70);
    int cm = sonar.ping_cm();
    return cm = cm == 250 ? 0 : cm;
}

void stopMoving()
{
    frontRight.run(RELEASE);
    frontLeft.run(RELEASE);
    rearRight.run(RELEASE);
    rearLeft.run(RELEASE);
}

void moveForward()
{
    frontRight.run(FORWARD);
    frontLeft.run(FORWARD);
    rearRight.run(FORWARD);
    rearLeft.run(FORWARD);
}

void moveBackward()
{
    frontRight.run(BACKWARD);
    frontLeft.run(BACKWARD);
    rearRight.run(BACKWARD);
    rearLeft.run(BACKWARD);
}

void turnRight()
{
    stopMoving();
    frontLeft.run(FORWARD);
    rearRight.run(FORWARD);

    rearLeft.run(RELEASE);
    frontRight.run(RELEASE);

    delay(500);

    frontLeft.run(FORWARD);
    frontRight.run(FORWARD);

    rearLeft.run(RELEASE);
    rearRight.run(RELEASE);
    stopMoving();
}

void turnLeft()
{
    stopMoving();
    rearLeft.run(FORWARD);
    frontRight.run(FORWARD);

    frontLeft.run(RELEASE);
    rearRight.run(RELEASE);

    delay(500);

    frontLeft.run(FORWARD);
    frontRight.run(FORWARD);

    rearLeft.run(RELEASE);
    rearRight.run(RELEASE);
    stopMoving();
}