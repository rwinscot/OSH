#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

#define BUTTON 5
#define LED 13

int lastState = 0;

void setup() {
    
    mySerial.begin(19200);
    
    pinMode(BUTTON,INPUT);
    pinMode(LED,OUTPUT);
}

void loop() {
    
    // Get the update value
    int value = digitalRead( BUTTON );
    
    if ( value != lastState )
    {
        lastState = value;
        
        // Turn on or off the LED
        if ( value == HIGH) {
            digitalWrite(LED, HIGH );
            
            mySerial.write( "1\n" );
            
            } else {
            digitalWrite(LED, LOW );
            
            mySerial.write( "0\n" );
        }
        
    }
    
    delay(100);
}
