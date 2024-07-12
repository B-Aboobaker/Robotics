// LEDRGBCircuit
# include <IRremote.h>
int red = 13;
int green = 9;
int blue = 10;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
    pinMode (red,OUTPUT);
    pinMode (blue,OUTPUT);
    pinMode (green,OUTPUT);
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop() {
    if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
        
        if (results.value == 0xFD08F7){
            digitalWrite(red,HIGH);
            digitalWrite(green,LOW);
            digitalWrite(blue,LOW);
        }
        else if (results.value == 0xFD48B7){
            digitalWrite(red,LOW);
            digitalWrite(green,LOW);
            digitalWrite(blue,HIGH);
        }
        else if (results.value == 0xFD8877){
            digitalWrite(red,LOW);
            digitalWrite(green,HIGH);
            digitalWrite(blue,LOW);
        }
    }
    delay(100);
}
