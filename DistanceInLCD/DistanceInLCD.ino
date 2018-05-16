#include<LiquidCrystal.h> //Please replace the single quote characters ('') with the parenthesis character (<>)

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int trigPin = 9;
const int echoPin = 10;
//long duration;
//int distanceCm, distanceInch;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

int duration = pulseIn(echoPin, HIGH);
float distanceCm= duration*0.03/2;
float distanceInch = duration*0.013/2;

lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance:"); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print("cm");
//delay(10);
lcd.setCursor(0,1);
lcd.print("Distance:");
lcd.print(distanceInch);
lcd.print("inch");
//delay(10);
delay(1000);
lcd.clear();

}
