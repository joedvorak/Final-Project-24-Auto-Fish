#include <LiquidCrystal.h>



//const int PushButton = 4; //Pushbutton on pin 4
int value = 0; // variable reading for the pushbutton.

// Below this line is for the Thermistor Readings

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
//initializing variables to be used.
int TempGreenLed=7;
int TempRedLed = 6;
int FloatSwitch = 5;
int LevelGreenLed = 4;
int LevelRedLed = 3;
int buttonState =1;


void setup() {
  // put your setup code here, to run once:
  //Setting pin modes for the LED's buttons and thermistor
  pinMode(TempGreenLed, OUTPUT);
  pinMode(TempRedLed, OUTPUT);
  pinMode (ThermistorPin, OUTPUT); 
  pinMode(FloatSwitch, INPUT_PULLUP);
  pinMode(LevelGreenLed, OUTPUT);
  pinMode(LevelRedLed, OUTPUT);
  //pinMode (PushButton, INPUT);
  
 lcd.begin(16, 2);  // Initialize the LCD: 16 characters and 2 lines
  lcd.setCursor(0, 0);// Set cursor position to (0, 0)
  //lcd.print("Feed Timer   "); // Print initial message on LCD
  //Serial.begin(9600);
  //delay(2000);
  

 
}

void loop() {
      //Reading value of thermistor to calculate the temps.
        Vo = analogRead(ThermistorPin);
        R2 = R1 * (1023.0 / (float)Vo - 1.0);
        logR2 = log(R2);
        T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
        Tc = T - 273.15; //Temp in Celsius
        T = (Tc * 9.0)/ 5.0 + 32.0; //Temp in F

        if (T > 90 || T < 75){ //Here is where we set desired temperature for the water
          digitalWrite(TempRedLed, HIGH); //if out of range, red light turns on
          digitalWrite(TempGreenLed, LOW); //if out of range, green light turns off
        } else {
          digitalWrite(TempRedLed, LOW); //if in  range, red light turns off
          digitalWrite(TempGreenLed, HIGH); //if in range, green light turns on

        }
        //Serial.print("Temperature: "); 
        //Serial.print(T);
        //Serial.println(" F"); 

        lcd.setCursor(0, 0);// Set cursor position to (0, 0)
        lcd.print("   Water Temp");

        lcd.setCursor(0, 1); //printing the temp in F to screen
        lcd.print(T);
        lcd.print(" F ");

        lcd.setCursor(8, 1); //printing the temp in C to screen
        lcd.print(" ");
        lcd.print(Tc);
        lcd.print(" C");

        delay(5000);

        lcd.setCursor(0, 0);   //Clearing off Screen for next message
        lcd.print("                     ");
        lcd.setCursor(0, 1);
        lcd.print("                   ");

        buttonState= digitalRead(FloatSwitch);
        if (buttonState == LOW){ 
          digitalWrite(LevelRedLed, HIGH); //if button not pressed, red light turns on
          digitalWrite(LevelGreenLed, LOW); //if button not pressed, green light turns off
          lcd.setCursor(0, 0);
          lcd.print("  Water Level"); //Printing water updates
          lcd.setCursor(0, 1);
          lcd.print(" LOW: ADD WATER");
          delay(5000);
          } else {
            digitalWrite(LevelGreenLed, HIGH); //if button pressed , green light turns on
            digitalWrite(LevelRedLed, LOW); //if button pressed, red light turns off
            lcd.setCursor(0, 0);
            lcd.print("  Water Level"); //Printing water updates
            lcd.setCursor(0, 1);
            lcd.print( "     Good ");
            delay(5000);
            }
      }





      



