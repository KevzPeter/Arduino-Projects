#define ledPin 7
bool flag = true;
void setup()
{
    // put your setup code here, to run once:
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    digitalWrite(ledPin, flag ? HIGH : LOW);
    delay(3000);
    flag = !flag;
}
