const byte blue = 5;
const byte green = 6;
const byte red = 7;

void setup()
{
    // put your setup code here, to run once:
    pinMode(blue, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(red, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    analogWrite(blue, random(0, 256));
    analogWrite(red, random(0, 256));
    analogWrite(green, random(0, 256));
    delay(500);
}
