#include <Arduino.h>

#define SPEAKER 3 //speaker
#define Humidade sensorValue

int BassTab[]={1911,1702,1516,1431,1275,1136,1012};//bass 1~7 //speaker

int sensorPin = A0;
int sensorValue = 0;

void pinInit() //speaker
{
    pinMode(SPEAKER,OUTPUT);
    digitalWrite(SPEAKER,LOW);
}
void sound(uint8_t note_index) //speaker
{
    for(int i=0;i<100;i++)
    {
        digitalWrite(SPEAKER,HIGH);
        delayMicroseconds(BassTab[note_index]);
        digitalWrite(SPEAKER,LOW);
        delayMicroseconds(BassTab[note_index]);
    }
}

void setup() {
    Serial.begin(9600);
     pinInit(); //speaker
}
void loop() {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    Serial.print("Moisture = " );
    Serial.println(sensorValue);
    delay(1000);
    

    if(Humidade<20)
            /*sound bass 1~7*/ //speaker
        for(int note_index=0;note_index<7;note_index++)
    {
        sound(note_index);
        delay(500);
    }
    else
               /*sound bass 1~7*/ //speaker
        for(int note_index=0;note_index<0;note_index++)
    {
        sound(note_index);
        delay(500);
    }
}

