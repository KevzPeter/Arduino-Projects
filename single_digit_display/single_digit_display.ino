int pinA = 13;
int pinB = 12;
int pinC = 11;
int pinD = 10;
int pinE = 9;
int pinF = 8;
int pinG = 7;

int t = 1000;

void setup()
{
    // put your setup code here, to run once:
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    // 0
    digitalWrite(pinA, 1);
    digitalWrite(pinB, 1);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 1);
    digitalWrite(pinE, 1);
    digitalWrite(pinF, 1);
    digitalWrite(pinG, 0);
    delay(t);

    // 1
    digitalWrite(pinA, 0);
    digitalWrite(pinB, 1);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 0);
    digitalWrite(pinE, 0);
    digitalWrite(pinF, 0);
    digitalWrite(pinG, 0);
    delay(t);

    // 2
    digitalWrite(pinA, 1);
    digitalWrite(pinB, 1);
    digitalWrite(pinC, 0);
    digitalWrite(pinD, 1);
    digitalWrite(pinE, 1);
    digitalWrite(pinF, 0);
    digitalWrite(pinG, 1);
    delay(t);

    // 3
    digitalWrite(pinA, 1);
    digitalWrite(pinB, 1);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 1);
    digitalWrite(pinE, 0);
    digitalWrite(pinF, 0);
    digitalWrite(pinG, 1);
    delay(t);

    // 4
    digitalWrite(pinA, 0);
    digitalWrite(pinB, 1);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 0);
    digitalWrite(pinE, 0);
    digitalWrite(pinF, 1);
    digitalWrite(pinG, 1);
    delay(t);

    // 5
    digitalWrite(pinA, 1);
    digitalWrite(pinB, 0);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 1);
    digitalWrite(pinE, 0);
    digitalWrite(pinF, 1);
    digitalWrite(pinG, 1);
    delay(t);

    // 6
    digitalWrite(pinA, 1);
    digitalWrite(pinB, 0);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 1);
    digitalWrite(pinE, 1);
    digitalWrite(pinF, 1);
    digitalWrite(pinG, 1);
    delay(t);

    // 7
    digitalWrite(pinA, 1);
    digitalWrite(pinB, 1);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 0);
    digitalWrite(pinE, 0);
    digitalWrite(pinF, 0);
    digitalWrite(pinG, 0);
    delay(t);

    // 8
    digitalWrite(pinA, 1);
    digitalWrite(pinB, 1);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 1);
    digitalWrite(pinE, 1);
    digitalWrite(pinF, 1);
    digitalWrite(pinG, 1);
    delay(t);

    // 9
    digitalWrite(pinA, 1);
    digitalWrite(pinB, 1);
    digitalWrite(pinC, 1);
    digitalWrite(pinD, 1);
    digitalWrite(pinE, 0);
    digitalWrite(pinF, 1);
    digitalWrite(pinG, 1);
    delay(t);
}
