#include <SoftwareSerial.h>

/*
  String to Integer conversion
 
 Reads a serial input string until it sees a newline, then converts
 the string to a number if the characters are digits.
 
 The circuit:
 No external components needed.
 
 created 29 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain. 
 */

#define LED 13

SoftwareSerial mySerial(2, 3);

String inString = "";    // string to hold input

void setup() {
  
  pinMode(LED,OUTPUT);
  
  // Initialize serial communications:
  mySerial.begin(19200);
  Serial.begin(9600);
}

void loop() {
  // Read serial input:
  while (mySerial.available() > 0) {
    int inChar = mySerial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char 
      // and add it to the string:
      inString += (char)inChar; 
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      Serial.println(inString.toInt());
      Serial.print("String: ");
      Serial.println(inString);
      // clear the string for new input:
      
      if ( inString.toInt() == 1 )
      {
        digitalWrite(LED, HIGH );
      }
      else
      {
        digitalWrite(LED, LOW );
      }
      
      inString = ""; 
    }
  }
}




