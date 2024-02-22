#include <AFMotor.h>

#define DISTANCE_SENSOR_ECHO A1
#define DISTANCE_SENSOR_TRIG A0
#define LED A2
#define MAX_DISTANCE 20
#define CAR_POWER 40   // Set this to any value between 0 - 100
#define BOOST_POWER 10 // Extra power while turning to increase turning angle

AF_DCMotor frontRight(1); // M1
AF_DCMotor frontLeft(2);  // M2
AF_DCMotor rearLeft(3);   // M3
AF_DCMotor rearRight(4);  // M4

int data = 0;
boolean movingForwards = false;
boolean carStopped = false;

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
    int distance = measureDistance();
    if (distance >= MAX_DISTANCE)
    {
        digitalWrite(LED, LOW);
        if (Serial.available())
        {
            data = Serial.read();
            Serial.print("Data from Bluetooth device: ");
            Serial.print(data);
            Serial.println();
            switch (data)
            {
            case 'A':
                Serial.println("Moving Forward ");
                moveForward();
                break;
            case 'B':
                Serial.println("Moving Backward");
                moveBackward();
                break;
            case 'C':
                Serial.println("Turning Left");
                turnLeft();
                break;
            case 'D':
                Serial.println("Turning Right");
                turnRight();
                break;
            case 'E':
                Serial.println("Stopping Car");
                stopMoving();
                break;
            default:
                Serial.println("Invalid Input");
            }
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
            delay(300);
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
    carStopped = true;
    frontRight.run(RELEASE);
    frontLeft.run(RELEASE);
    rearRight.run(RELEASE);
    rearLeft.run(RELEASE);
}

void moveForward()
{
    carStopped = false;
    movingForwards = true;
    frontRight.run(FORWARD);
    frontLeft.run(FORWARD);
    rearRight.run(FORWARD);
    rearLeft.run(FORWARD);
}

void moveBackward()
{
    carStopped = false;
    movingForwards = false;
    frontRight.run(BACKWARD);
    frontLeft.run(BACKWARD);
    rearRight.run(BACKWARD);
    rearLeft.run(BACKWARD);
}

void turnRight()
{
    int boostedCarSpeed = convertPowerToSpeed(CAR_POWER + BOOST_POWER);
    setCarSpeed(boostedCarSpeed);
    if (movingForwards)
    {
        frontLeft.run(FORWARD);
        rearLeft.run(FORWARD);
        frontRight.run(BACKWARD);
        rearRight.run(BACKWARD);
    }
    else
    {
        frontLeft.run(BACKWARD);
        rearLeft.run(BACKWARD);
        frontRight.run(FORWARD);
        rearRight.run(FORWARD);
    }

    delay(200);

    int carSpeed = convertPowerToSpeed(CAR_POWER);
    setCarSpeed(carSpeed);
    if (!carStopped)
    {
        if (movingForwards)
        {
            moveForward();
        }
        else
        {
            moveBackward();
        }
    }
    else
    {
        stopMoving();
    }
}

void turnLeft()
{
    int boostedCarSpeed = convertPowerToSpeed(CAR_POWER + BOOST_POWER);
    setCarSpeed(boostedCarSpeed);

    if (movingForwards)
    {
        frontRight.run(FORWARD);
        rearRight.run(FORWARD);
        frontLeft.run(BACKWARD);
        rearLeft.run(BACKWARD);
    }
    else
    {
        frontRight.run(BACKWARD);
        rearRight.run(BACKWARD);
        frontLeft.run(FORWARD);
        rearLeft.run(FORWARD);
    }

    delay(200);

    int carSpeed = convertPowerToSpeed(CAR_POWER);
    setCarSpeed(carSpeed);

    if (!carStopped)
    {
        if (movingForwards)
        {
            moveForward();
        }
        else
        {
            moveBackward();
        }
    }
    else
    {
        stopMoving();
    }
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