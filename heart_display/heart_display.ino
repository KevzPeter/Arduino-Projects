// Mario's Ideas
// Testing all 64 leds in 8x8 LED matrix by lighting  them up one by one

// Raws
#define R1 2
#define R2 7
#define R3 A3
#define R4 5
#define R5 13
#define R6 A2
#define R7 12
#define R8 A0
// Columns
#define C1 6
#define C2 11
#define C3 10
#define C4 3
#define C5 A1
#define C6 4
#define C7 8
#define C8 9

int pause = 300;

int MATRIX[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 1, 1, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

void setup()
{
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
    pinMode(R4, OUTPUT);
    pinMode(R5, OUTPUT);
    pinMode(R6, OUTPUT);
    pinMode(R7, OUTPUT);
    pinMode(R8, OUTPUT);
    pinMode(C1, OUTPUT);
    pinMode(C2, OUTPUT);
    pinMode(C3, OUTPUT);
    pinMode(C4, OUTPUT);
    pinMode(C5, OUTPUT);
    pinMode(C6, OUTPUT);
    pinMode(C7, OUTPUT);
    pinMode(C8, OUTPUT);
    // Turning all the LEDs off at the startof the sketch
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);
    digitalWrite(R5, LOW);
    digitalWrite(R6, LOW);
    digitalWrite(R7, LOW);
    digitalWrite(R8, LOW);

    digitalWrite(C1, HIGH);
    digitalWrite(C2, HIGH);
    digitalWrite(C3, HIGH);
    digitalWrite(C4, HIGH);
    digitalWrite(C5, HIGH);
    digitalWrite(C6, HIGH);
    digitalWrite(C7, HIGH);
    digitalWrite(C8, HIGH);

    Serial.begin(9600);
}

void SelectRow(int row)
{
    if (row == 1)
        digitalWrite(R1, HIGH);
    else
        digitalWrite(R1, LOW);
    if (row == 2)
        digitalWrite(R2, HIGH);
    else
        digitalWrite(R2, LOW);
    if (row == 3)
        digitalWrite(R3, HIGH);
    else
        digitalWrite(R3, LOW);
    if (row == 4)
        digitalWrite(R4, HIGH);
    else
        digitalWrite(R4, LOW);
    if (row == 5)
        digitalWrite(R5, HIGH);
    else
        digitalWrite(R5, LOW);
    if (row == 6)
        digitalWrite(R6, HIGH);
    else
        digitalWrite(R6, LOW);
    if (row == 7)
        digitalWrite(R7, HIGH);
    else
        digitalWrite(R7, LOW);
    if (row == 8)
        digitalWrite(R8, HIGH);
    else
        digitalWrite(R8, LOW);
}

void SelectColumn(int column)
{
    if (column == 1)
        digitalWrite(C1, LOW);
    else
        digitalWrite(C1, HIGH);

    if (column == 2)
        digitalWrite(C2, LOW);
    else
        digitalWrite(C2, HIGH);
    if (column == 3)
        digitalWrite(C3, LOW);
    else
        digitalWrite(C3, HIGH);
    if (column == 4)
        digitalWrite(C4, LOW);
    else
        digitalWrite(C4, HIGH);
    if (column == 5)
        digitalWrite(C5, LOW);
    else
        digitalWrite(C5, HIGH);

    if (column == 6)
        digitalWrite(C6, LOW);
    else
        digitalWrite(C6, HIGH);
    if (column == 7)
        digitalWrite(C7, LOW);
    else
        digitalWrite(C7, HIGH);
    if (column == 8)
        digitalWrite(C8, LOW);
    else
        digitalWrite(C8, HIGH);
}

void Set_LED_in_Active_Row(int column, int state)
{
    if (column == 1)
        digitalWrite(C1, state);
    if (column == 2)
        digitalWrite(C2, state);
    if (column == 3)
        digitalWrite(C3, state);
    if (column == 4)
        digitalWrite(C4, state);
    if (column == 5)
        digitalWrite(C5, state);
    if (column == 6)
        digitalWrite(C6, state);
    if (column == 7)
        digitalWrite(C7, state);
    if (column == 8)
        digitalWrite(C8, state);
}

void loop()
{
    for (int j = 0; j < 8; j++)
    {
        SelectRow(j + 1);
        for (int i = 0; i < 8; i++)
        {
            Set_LED_in_Active_Row(i + 1, MATRIX[j][i] ^ 1);
        }
        delay(2);
    }
}