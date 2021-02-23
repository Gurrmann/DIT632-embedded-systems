const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad

//keyMap defines the key pressed according to the row and columns just as appears on the keypad
char keyMap[numRows][numCols]=
{
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {11,10,9,8}; //Rows 0 to 3{11,10,9,8};
byte colPins[numCols] = {6,5,4,3}; //Columns 0 to 3

void scan(){

    for (byte column = 0; column < numCols; column++) {

        pinMode(colPins[column], OUTPUT); // The column pins are output pins as they deliver the power
        digitalWrite(colPins[column], LOW);

        for (byte row = 0; row < numRows; row++) {

            pinMode(rowPins[row], INPUT_PULLUP);

            // Because of INPUT_PULLUP, the pin will read LOW when the switch is pressed
            if (digitalRead(rowPins[row]) == LOW)
            {
                Serial.print(keyMap[row][column]);
            }
        }
        digitalWrite(colPins[column], HIGH);
    }
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    scan();
    delay(50);
}