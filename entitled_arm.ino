/*
 * Creation & Computation - Digital Futures, OCAD University
 * Madlibs Project,Entitled Arm
 * Quinn Rockliff / Kristy Boyce
 * With code from Kate Hartman / Nick Puckett
 * 
 * Read Potentiometer, scale the value to different ranges and print it over the Serial port
 *  
 * 
 * 
 */

 #include <Servo.h>

int potentiometerPin = A1;  //the analog input pin the sensor is attached to
int rawValue;   //variable to hold the raw bit value 0 -1023
int scaledVal2; //map this one to a rotational value
int emptyTime = 0;


Servo s1;
void setup() 
{
 s1.attach(10);
Serial.begin(9600);  //turn on the serial port
}

void loop() 
{

  rawValue = analogRead(potentiometerPin);  //read the sensor value and store it
  scaledVal2 = map(rawValue,70,380,0,90);  // do it again

  s1.write(scaledVal2 );
  Serial.print("Raw Value : ");             //print all of this out of the serial monitor
  Serial.print(rawValue);
  Serial.print(" ");
  Serial.print("Scaled for brightness : "); // scale for brightness
  
  Serial.print(" ");
  Serial.print("Scaled for rotation : ");
  Serial.println(scaledVal2);              
 

if (scaledVal2 > 80)             // if glass is empty
{
  emptyTime += 1;             // start counting 
}

  else{emptyTime = 0;         // or just keep mapping brightness
  }

  if(emptyTime > 3000)      // if glass empty for longer than this time
{
  s1.write(random(70,80)); // Shake the hand
}

}

