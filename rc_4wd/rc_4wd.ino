#include <AFMotor.h>

#define CAR_POWER 40   // Set this to any value between 0 - 100
#define BOOST_POWER 10 // Extra power while turning to increase turning angle

AF_DCMotor frontRight(1); // M1
AF_DCMotor frontLeft(2);  // M2
AF_DCMotor rearLeft(3);   // M3
AF_DCMotor rearRight(4);  // M4
int data = 0;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    int carSpeed = convertPowerToSpeed(CAR_POWER);
    setCarSpeed(carSpeed);
    stopMoving();

    Serial.println("Ready to roll!");
}

void loop()
{
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

    delay(250);
}

int convertPowerToSpeed(int power)
{
    power = min(100, power);
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
    int boostedCarSpeed = convertPowerToSpeed(CAR_POWER + BOOST_POWER);
    setCarSpeed(boostedCarSpeed);

    frontLeft.run(FORWARD);
    rearLeft.run(FORWARD);
    frontRight.run(BACKWARD);
    rearRight.run(BACKWARD);

    delay(750);

    stopMoving();
    int carSpeed = convertPowerToSpeed(CAR_POWER);
    setCarSpeed(carSpeed);
}

void turnLeft()
{
    int boostedCarSpeed = convertPowerToSpeed(CAR_POWER + BOOST_POWER);
    setCarSpeed(boostedCarSpeed);

    frontRight.run(FORWARD);
    rearRight.run(FORWARD);
    frontLeft.run(BACKWARD);
    rearLeft.run(BACKWARD);

    delay(750);

    stopMoving();
    int carSpeed = convertPowerToSpeed(CAR_POWER);
    setCarSpeed(carSpeed);
}