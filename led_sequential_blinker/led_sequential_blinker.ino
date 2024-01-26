#define LED1 5
#define LED2 6
#define LED3 7
#define DELAY 250

void setup()
{
    // put your setup code here, to run once:
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    digitalWrite(LED1, HIGH);
    delay(DELAY);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(DELAY);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    delay(DELAY);
    digitalWrite(LED3, LOW);
}
