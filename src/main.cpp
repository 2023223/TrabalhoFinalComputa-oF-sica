#include <Arduino.h>
#include <ChainableLED.h> //led

#define SPEAKER 3 //speaker
#define NUM_LEDS 5 //leds
#define Humidade sensorValue //moisture

ChainableLED leds(7, 8, NUM_LEDS); //leds

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

float hue = 0.0; //leds
boolean up = true;

void loop() {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    Serial.print("Moisture = " );
    Serial.println(sensorValue);
    delay(1000);
    
    for (byte i=0; i<NUM_LEDS; i++) //leds
    leds.setColorHSB(i, hue, 1.0, 0.5); // Alterado de HSL para HSB

    delay(50);

    if(Humidade<100) //leds
         if (up)
    hue+= 0.025;
         else
    hue-= 0.025;
    
        if (hue>=1.0 && up)
    up = false;
        else if (hue<=0.0 && !up)
    up = true;
    else
             if (up)
    hue+= 0.025;
         else
    hue-= 0.025;
    
        if (hue>=1.0 && up)
    up = true;
        else if (hue<=0.0 && !up)
    up = false;

    if(Humidade<20) //speaker
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

