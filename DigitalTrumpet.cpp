// C++ code
//
//set the pins for the button and buzzer
int firstKeyPin = 2;
int secondKeyPin = 3;
int thirdKeyPin = 4;
int buzzerPin = 10;

void setup()
{
    //set the button pins as inputs
    pinMode(firstKeyPin, INPUT_PULLUP);
    pinMode(secondKeyPin, INPUT_PULLUP);
    pinMode(thirdKeyPin, INPUT_PULLUP);

    //set the buzzer pin as an output
    pinMode(buzzerPin, OUTPUT);
}

void loop()
{
    if(digitalRead(firstKeyPin) == LOW){
        tone(buzzerPin, 262);
    }
    else if(digitalRead(secondKeyPin) == LOW){
        tone(buzzerPin, 330);
    }
    else if(digitalRead(thirdKeyPin) == LOW){
        tone(buzzerPin, 392);
    }
    else{
        noTone(buzzerPin);
    }
}

/*
note   frequency
c       262 Hz
d       294 Hz
e       330 Hz
f       349 Hz
g       392 Hz
a       440 Hz
b       494 Hz
C       523 Hz
*/
