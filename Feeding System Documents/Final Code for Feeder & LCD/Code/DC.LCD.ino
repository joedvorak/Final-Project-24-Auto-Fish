#include <LiquidCrystal.h>
#include <Stepper.h>

//Define button and LCD pins
const int buttonPinSet = 7; //Button for setting the feeding interval
const int resetButton = 4; //Button for resetting 
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; //LCD Pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Adding the LCD screen

// Constants for potentiometer and motor
const int potentiometerPin = A0;  // Potentiometer connected to analog pin A0
const int stepsPerRevolution = 2048; // This is max speed for our stepper motor
Stepper myStepper = Stepper(stepsPerRevolution, 2, 3, 5, 6); //purple is #8 & stepper motor initiation

// Variables
bool motorOn = false; //setting motor status
unsigned long motorStartTime = 0; //Time when motorstarts
unsigned long interval = 0; // Initial interval to zero
int potValue = 0; //initial potentiometer value
bool potentiometerSet = false; //flag for the potentiometer setting



void setup() {
  //set the modes of the pins
  pinMode(buttonPinSet, INPUT_PULLUP);// Set pin for setting interval as input with pull-up
  pinMode(resetButton, INPUT_PULLUP);// Set reset button pin as input with pull-up

    // Initialize the LCD
  lcd.begin(16, 2);  // Initialize the LCD: 16 characters and 2 lines
  lcd.setCursor(0, 0);// Set cursor position to (0, 0)
  lcd.print("Feed Timer   "); // Print initial message on LCD
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate

  
  

}



void loop() {

  //unsigned long firstMillis = millis();

  if (digitalRead(buttonPinSet) == LOW && !potentiometerSet) {
    lcd.clear();// Clear the LCD
    lcd.setCursor(0, 0); // Set cursor to (0, 0)
    lcd.print("Set Feed Timer:   "); // Print message to set feed timer
    lcd.setCursor(0, 1);  // Set cursor to (0, 1)
    lcd.print("                "); // Clear previous message
    
    //lcd.setCursor(0, 1);
    //lcd.print(" ");


    // While button is pressed, read potentiometer and display interval options
    while (digitalRead(buttonPinSet) == LOW) {
      // Read the potentiometer value and display
      potValue = analogRead(potentiometerPin);  // Read potentiometer value
      lcd.setCursor(0, 1); // Set cursor to (0, 1)
      if(potValue >= 0 && potValue <= 255){
        lcd.print("6  Hr Intervals   "); // Print interval option
      } else if (potValue >= 256 && potValue <= 510){
        lcd.print("12 Hr Intervals    ");  // Print interval option
      } else if (potValue >= 511 && potValue <= 765){
        lcd.print("24 Hr Intervals      ");  // Print interval option
      }else if (potValue >= 766 && potValue <= 1023) {
      lcd.print("Test Interval       ");  // Print interval option
    }

      delay(50);  // Small delay for stability
    }

    potentiometerSet = true;  // Set flag to true
    lcd.setCursor(0, 0);  // Set cursor to (0, 0)
    lcd.print("Feeding Schedule   ");  // Print message on LCD
    lcd.setCursor(0, 1);  // Set cursor to (0, 1)
    lcd.print("  Has Been Set    ");  // Print message on LCD
    delay(2000);  // Delay for stability
    
  }



  // Map the potentiometer value to the interval range

  if (potentiometerSet) {
    if (potValue >= 0 && potValue <= 255) {
      interval = 21600000; // 6 hours in millis
    }   else if (potValue >= 256 && potValue <= 510) {
      interval = 43200000; // 12 hours in millis
    }   else if (potValue >= 511 && potValue <= 765) {
      interval = 86400000; // 86400000 for 24 hours
    } else if (potValue >= 766 && potValue <= 1023) {
      interval = 10000; // 86400000 for 24 hours
    }
  
    //Serial.println(interval);  // Print interval to serial monitor
    delay(700);
  // If the potentiometer is turned, turn on motor
   if (potValue != 0 && !motorOn ) {
     motorOn = true;  // Set motor status to on
     motorStartTime = millis();  // Record motor start time
     lcd.clear();  // Clear the LCD
     lcd.setCursor(0, 0);  // Set cursor to (0, 0)
     lcd.print("Auger ON");  // Print "Auger ON" message on LCD

     delay(100);


      
   }
  
  // If motor is on, calculate time remaining and display on LCD
   if (motorOn) {
     unsigned long currentMillis = millis(); // Get current time
      unsigned long motorElapsedTime =0; // Motor elapsed time

       // Run the motor for 3 (however long is needed) seconds
        while (motorElapsedTime < 3000) {
          myStepper.setSpeed(10); // Set motor speed
          myStepper.step(1); // Move one step
          delay(10); // Adjust delay for desired speed
          motorElapsedTime = motorElapsedTime +10; // Increment elapsed time
        }
             delay(100);
            motorElapsedTime = 3100; // Reset motor elapsed time for next cycle
            delay(100);

     if (motorElapsedTime > 3000) {
        delay(100);
       lcd.clear(); // Clear the LCD
       delay(100);
       lcd.setCursor(0, 0); // Set cursor to (0, 0)
       delay(100);
       lcd.print("Auger OFF"); // Set cursor to (0, 0)
       delay(1000); // Small delay for stability


        unsigned long newcurrentMillis = millis(); // Get current time

      int remainingTime =0; //Remaining Time


      // Calculate remaining time and display on LCD
      while(remainingTime<=0){
        unsigned long elapsedTime = millis() - newcurrentMillis; // Calculate elapsed time
        delay(100);

        unsigned long remainingTime = interval - elapsedTime; // Calculate remaining time
          
         // Serial.println(remainingTime); // Print remaining time to serial monitor
        int hours = remainingTime / (3600000); // Calculate hours
        //Serial.println("hours is ");
        //Serial.println(hours);

        int minutes = (remainingTime % (3600000)) / (60000); // Calculate mins
        //Serial.println("mins is ");
        //Serial.println(minutes);

        int seconds = (remainingTime % (60000)) / 1000; // Calculate seconds
        //Serial.println("sec is ");
        //Serial.println(seconds);

       lcd.setCursor(0, 1);    // Calculate hours
       lcd.print("Time: ");    // Print "Time:" message on LCD
       lcd.print(hours);       // Print hours on LCD
       delay(10);              // Small delay for stability
       lcd.print("h ");        // Print "h" on LCD
       lcd.print(minutes);     // Print minutes on LCD
       delay(10);              // Small delay for stability
       lcd.print("m ");        // Print "m" on LCD 
       lcd.print(seconds);     // Print seconds on LCD
       delay(10);              // Small delay for stability
       lcd.print("s ");        //Print "s" on LCD 
       delay(10);              // Small delay for stability


        // Reset all variables and flags if reset button is pressed
       if (digitalRead(resetButton) == HIGH) {
         // Reset all variables and flags
        motorOn = false;
        potentiometerSet = false;
        interval = 0;
        potValue = 0;
    
        lcd.clear(); // Clear the LCD
        lcd.setCursor(0, 0); // Set cursor to (0, 0)
        lcd.print("Resetting...    "); // Print "Resetting..." message on LCD
        delay(1000); // Delay for stability
    
        // Re-initialize the LCD display
        lcd.clear();
        lcd.setCursor(0, 0);
          }


          // Break loop if interval is greater than 864,000,000 milliseconds (24 hours)
          if (remainingTime > 864000000){
            lcd.setCursor(0, 0); // Set cursor to (0, 0)
            lcd.print("Auger ON         "); // Print "Auger ON" message on LCD
            delay(10); // Small delay for stability
            lcd.setCursor(0, 1); // Set cursor to (0, 1)
            lcd.print("Feeding Occuring"); // Print "Feeding Occuring" message on LCD
            break; // Exit the loop
          }
          delay(700); // Small delay for stability
        }
       }
     }  
    }
  }



  

