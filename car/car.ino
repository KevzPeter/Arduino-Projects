#include <AFMotor.h>

#define DISTANCE_SENSOR_ECHO A5
#define DISTANCE_SENSOR_TRIG A4
#define LED A2
#define MAX_DISTANCE 20
#define CAR_POWER 70 // 0-100

AF_DCMotor frontRight(1); // M1
AF_DCMotor frontLeft(2);  // M2
AF_DCMotor rearLeft(3);   // M3
AF_DCMotor rearRight(4);  // M4

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    int carSpeed = convertPowerToSpeed(CAR_POWER);
    setCarSpeed(carSpeed);
    stopMoving();

    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
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
    int distance = measureDistance();
    if (distance >= MAX_DISTANCE)
    {
        digitalWrite(LED, LOW);
        if (data == 'A')
        {
            Serial.println("Moving Forward ");
            moveForward();
        }
        else if (data == 'B')
        {
            Serial.println("Moving Backward");
            moveBackward();
        }
        else if (data == 'C')
        {
            Serial.println("Turning Left");
            turnLeft();
        }
        else if (data == 'D')
        {
            Serial.println("Turning Right");
            turnRight();
        }
    }
    else
    {
        Serial.println(distance);
        Serial.println("Obstacle detected. Stopping car...");
        digitalWrite(LED, HIGH);
        stopMoving();
        while (measureDistance() < MAX_DISTANCE)
        {
            moveForward();
            delay(500);
        }
        digitalWrite(LED, LOW);
        stopMoving();
    }
    delay(250);
}

int convertPowerToSpeed(int power)
{
    return map(power, 0, 100, 0, 255);
}

void setCarSpeed(int speed)
{
    frontRight.setSpeed(speed);
    frontLeft.setSpeed(speed);
    rearLeft.setSpeed(speed);
    rearRight.setSpeed(speed);
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

int measureDistance()
{
    digitalWrite(DISTANCE_SENSOR_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(DISTANCE_SENSOR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(DISTANCE_SENSOR_TRIG, LOW);

    float duration = pulseIn(DISTANCE_SENSOR_ECHO, HIGH);
    float distance = (duration * .0343) / 2;
    return floor(distance);
}