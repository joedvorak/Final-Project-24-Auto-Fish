# BAE305 Final Project: Automatic Fish Tank Feeder
***BAE305 Final Project***
* Eli Barrow
* Alexis Puckett
* Hannah Markwell

## Summary:

Our BAE305 project is for an aquarium monitoring and feeding system. The system includes an automatic feeder that is on a timer for periods of 6 hours, 12 hours, and 24 hours, and it distributes food directly to the fish in the tank. The feeder uses an auger and stepper motor to push the fish food out of the container, into the fish tank. Our project also includes a mechanism that reads the temperature, displays it, and then turns on a red LED if the temperature falls below a specified point, and a green LED if the temperature is good for the safety of the fish. It also includes a feature that monitors the water level of the fish tank, and this feature turns on an LED to alert low water levels in the tank. Our display system displays the red and green LEDs for both the temperature and water level monitoring systems. It also has two screens, one to show the temperature and water level data, and one to show how much time is left until the next feeding. We used a potentiometer for the user to change the feeding time from 6, 12, and 24 hours. Finally, our display has two potentiometers to control the contrast of the screens. Both the feeder and display mechanical systems are 3D printed.

[Project Video Description: (https://www.youtube.com/shorts/zOCTcbQEuwI)](https://www.youtube.com/shorts/zOCTcbQEuwI)

## Design Description

### Materials:
 
For this project the materials needed are simple electrical components as well as the ability to access a 3D printer to print the larger mechanical parts of the system.
 The electrical components needed are:
 - 2 Arduino Uno Boards with Breadboards
 - Ability to connect the Uno to your computer
 - Approx. 50 wires that're compatible with the Arduino, Breadboard, and components
 - 2 LCD Screens
 - 1 5V DC Stepper Motor (ROHS 28byj-48)
 - 3 Potentiometers
 - 2 Push buttons
 - 2 Green LEDs
 - 2 Red LEDs
 - 1 Float Switch
 - 1 Thermistor
 - 6 1kOhm Resistors 
 - 1 10kOhm Precision Resistor (for thermistor)
 - 1 10 kOhm Resistor


 ### Physical Design: 

The design of the feeding system was a small hopper with an auger in the bottom of it that would be turned by a stepper motor to slowly push the food out of the front of the hopper body. There is a hole that runs from the back of the hopper body to the front of the hopper body where the auger slides into, with a stop being placed on the front side that does not allow the auger to slide all the way through. Below this stop is the funnel shape that the food will slide down into the tank to reach the fish. The base of the auger is specially designed to allow the shaft of the stepper motor to mate into the auger, connecting the two for a smooth rotational motion. The stepper motor came with a screw mounting bracket on each side, we then measured the size of those holes with calipers then created two extrusions on the back side of the hopper that would be used to mount the stepper motor. Then finally for a flush fit of the auger with the back wall of the hopper body some spacers were needed to be put on the shaft to create the proper offset of the stepper motor. The type of food that is normally given to the fish is very small spherical pellets that would almost flow fluidly in a system like this, so this design is what the team moved forward with. There was also a need for the hopper to be mounted to the back glass of the fish tank since there is no spot for the hopper to sit on top of the lid, so the team designed a bracket that mounts to the back glass of the tank for the hopper/feeding system to sit on. The design drawings of the Hopper, Bracket, Auger, and Spacers are shown below, as well as links to the online design file through OnShape, where the .stl files can be exported for 3D printing purposes.

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Feeder/Feeder/Hopper.png" width = 50%><img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Feeder/Auger%20%26%20HexSpacer/Auger.png" width = 50%>
</p>

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Feeder/Feeder%20Bracket/HOPPER%20STAND.png" width = 50%><img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Feeder/Assembly/Feeding%20Assembly.png" width = 50%>
</p>

**Link for Onshape Feeder Files:**
https://cad.onshape.com/documents/4df08dd93363a5b6d688b396/w/b2cb09403d87c3bcf0b51dba/e/0a122a04bef23e0f82b38aa6?renderMode=0&uiState=6621793480254631186acf1b


 After designing the Feeding system there was also a need to mount the thermistor and float switch to the back glass of the fish tank alongside the feeder. This only needed a few measurements taken of the float switch diameter and thermistor wire diameter to make a simple bracket, similar to the hopper bracket. The drawing file is shown below and is accompanied with a link to OnShape.


<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Temp%26Float%20Switch%20Bracket/Float%20Switch%20Bracket%20Drawing.png" width = 50%>
</p>


**Link for Onshape Float Switch & Thermistor Bracket Files:**   
https://cad.onshape.com/documents/ca7b3c8a11bfe362b02dd540/w/57267339f03928a64975b33e/e/b6ae37b48c85a3c1fea425d9?renderMode=0&uiState=6621795a283cfb13c7dd5678

**Picture of Assembly on Tank with Hopper and Float Switch Bracket:**
<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/Real%20Pictures/IMG_3664.jpg" width = 50%>
</p>


Once the measurement tools and feeding systems were designed the only piece remaining was a panel for the user to control the system with. The group had previously put together the circuits for the project and had previously known that we need positions for a selecting button, reset button, a potentiometer for choosing the time interval, spaces for 4 LEDs, 2 spaces for LCD screens and finally 2 more potentiometers for controlling the contrast of the screens. The group measured the dimensions of the electrical components with calipers and put together the following control panel that will be used to control the system. The control panel also was in need of a back plate that could be removed that would allow someone to connect wires to the electrical components. There was also a need for braces that would keep the LCD screens in place to assure that they would be flush with the front surface of the control panel for a smooth exterior look. The tolerances were tight enough for the smaller components, so they did not need braces to be held into place. The drawing file of the control panel, back plate, internal braces, and assembly drawing is shown below and is accompanied with a link to OnShape.

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Control%20Panel/Panel/Control%20Panel%20Drawing.png" width = 50%><img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Control%20Panel/Back%20Plate/Back%20Plate%20Drawing.png" width = 50%>
</p>

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Control%20Panel/Braces/LCD%20Brace%20Drawing.png" width = 50%><img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Control%20Panel/Assembly/Control%20Panel%20Assembly.png" width = 50%>
</p>

**Link for Onshape Control Panel Files:**   
https://cad.onshape.com/documents/7f8683062ff1f39808deca4c/w/c8f5f551fcbae8743f684af5/e/5d18dd19f17cefe8056f8dae    

**Picture of Final Control Panel:**
<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/Real%20Pictures/IMG_3663.jpg" width = 50%>
</p>

 

 ### Circuits:
For our project, we used two seperate Arduinos to run everything. One Arduino controlled the temperature and water level system and the other controlled the feeder system. These Arduinos are not in communication with eachother. We thought this would be best in order to simplify the code, and if one system failed to work, the other one could still work.

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/Monitoring%20System%20Documents/Temp%20%26%20Water%20Level%20Circuit/Schematics/Screenshot%202024-04-06%20at%2011.44.04%20AM.png" width = 50%>
</p>

**NOTE:** The push button on this schematic is representing the float switch. The software used did not provide a float switch so this was best option. The resistor connected to the thermistor is the 10k precision resistor.

The above schematic is for the temperature and water level sensor system. It uses an Arduino Uno Board, a common breadboard, a 10kOhm precision resistor, four 1kOhm resistor, two red LEDs, two green LEDs, a thermistor, a potentiometer, a float switch, and a LCD screen. The potentiometer is to control the contrast of the LCD screen. This screen displays both the temperature and the waterlevel information.

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/Feeding%20System%20Documents/Final%20Code%20for%20Feeder%20%26%20LCD/Schematics/Image%20of%20Schematic.png" width = 50%>
</p>

The above schematic is for the temperature and water level sensor system. It uses an Arduino Uno Board, a common breadboard, a 10kOhm precision resistor, four 1kOhm resistor, two red LEDs, two green LEDs, a thermistor, a potentiometer, a float switch, and a LCD screen. The potentiometer is to control the contrast of the LCD screen. This screen displays both the temperature and the water level information.

 ### Code: ###

 Sine the code for our project is a few hundred lines long, it will be included in links below to another section in this repository. Both of these links are the .INO files that can be downloaded and ran in the arduino software.(Both sets of code are equipped with comments describing the purpose of each line)   
 **Link for Feeder Code:**   
https://github.com/elibarrow/Final-Project/blob/main/Feeding%20System%20Documents/Final%20Code%20for%20Feeder%20%26%20LCD/Code/DC.LCD.ino   

 **Link for Monitoring Code:**   
 https://github.com/elibarrow/Final-Project/blob/main/Monitoring%20System%20Documents/Temp%20%26%20Water%20Level%20Circuit/Code/Temp.FloatSwitch.ino


 ### Assembly:

 The assembly part of this project was mostly simple. We had already created the schematics of the wiring and had previously uploaded the code to the Arduino boards. The 3d printed parts had already been confirmed to fit properly together, so there was no worry associated with that aspect. One minor issue that we ran into while assembly the final product was that we needed a few longer wires to connect everything together because of the size of the two Arduino boards, but this was a simple fix of just ordering some longer wires. The final minor issue that we ran into was the wires not staying put into the breadboard or staying attached to the pins on the button, we just made sure that everything was properly connected before testing out project. If this problem became serious enough, we could have soldered the connections together, which would have completely gotten rid of this issue.

 **Picture of Finished Project on the Fish Tank:**
<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/Real%20Pictures/IMG_3662.jpg" width = 50%>
</p>
 

## Test Description
 The project that we created should be somewhat simple to test. Beginning with the control panel user inputs, by turning the potentiometer that is to the left of the top LCD screen it will change the time interval for the next scheduled feeding. There will be options for a 6 hr., 12 hr., 24 hr., & a Test interval. To choose an interval the green select button needs to be pressed while the desired interval is on the screen. As assumed the 6 hr., 12 hr., and 24 hr. intervals will begin with a feeding of approximately 15 seconds, the screen will show "Auger On" during this period. Afterwards the timer will begin to count down for the selected interval, however for testing purposes, the Test option is only set to a 10 second timer. This makes the feeding almost constant, running a new 15 second feeding every 10 seconds, which allows for the user to assure that the auger is properly turning and dispensing food before setting the longer timer. However, if something happens and you need to reset the feeding system you can press the reset button, but only while the countdown is happening on the screen. The reset button has no effect while the auger is dispensing food. After pressing the reset button, you may choose a new feeding cycle and start the process over again.    
The other part of the system to look at will be the monitoring system, this system has no user inputs and only displays the information that has been gathered by the float switch and thermistor. There are a green and red LED for both the temperature and water level. As the temperature reaches the desired amount that has been set in the code the green light will be illuminated, but if the temperature exceeds or drops below that interval the red light will turn on. Likewise, as the float switch is down, the red light will be illuminated showing the water level is low, but if it is up the green light will be on signaling good water levels. Both of these inputs are also displayed on the LCD screen. The temperature is given in F and C, if these values are extremely high or low you might want to assure the thermistor is properly connected to the breadboard. Similarly, the LCD screen will then switch to give a status update on the water level, if the water is low, it will tell the user to put more water in the tank, if the water is at a good level it will say "Water level good". The LCD screen flips back and forth between the temperature and the water level about every 10 seconds, which also means the LEDs update every 10 seconds.   
A good testing procedure would be to let the system run for a few hours to make sure that everything is running properly for an extended period of time.


## Design Decision Discussion

The design of this system was purely driven by one of the group member's experiences with being away from a fish tank at their home for an extended period of time and not being able to feed their fish. After the group began considering this, the others then added some other features to add to the system, rather than just making a fish feeder. This ultimately led the group to pursue a design that included an automatic feeder, water temperature monitor and a water level monitor. The mechanical design of the project was strictly driven by the constraints that were presented by the fish tank that it was being designed for. The fish tank did not have a viable place for a feeder to sit on the lid, but there is an opening in the backside of the lid that would allow for the feeder to be attached to the glass, as well as the addition of a temperature sensor and water level sensor. Since this project had a budget of $0, we chose materials that were very cheap and used online software that is free to use, such as OnShape and TinkerCAD.



## Results

The capabilities of the entire project are fully described in the Test description part of this report. There is not any outside equipment that is needed to test the system, but you could run the system for a few hours to make sure the timing is working properly, and nothing will go wrong. This design is specific to only to fish tank it was designed for, but it could be integrated into other fish tanks or systems by changing the type of mounting brackets. The mounting brackets made were specific to the targeted fish tank and it is highly unlikely that any other tank will have the same dimensions. After conducting numerous hours of testing our system works very fluidly, the only noticeable flaw is the countdown timer stays on certain numbers because it only updates once every second, if it were to update more often this would not be an issue. For example, when it takes a reading at 4.99 seconds it displays 4 seconds, but when it may jump the gun and reads at 4.01 seconds, it still displays 4 seconds for the next duration. Although the displaying of this may be a little off the true internal timer is accurate and will work as described. The limitations of this system will be if it is in a moist environment, some of the electrical components may end up rusting or not working properly. There should be some sort of water protection over the Arduinos to make sure this is not an issue. This system is incapable of knowing how much food to dispense at one time depending on volume, it dispenses based on a time interval. The same volume of food being dispensed every time is highly unlikely.   
 When the group began doing final testing on the project the first test was to let it run through each cycle completely to make sure it worked properly, and after each one of those tests, no flaws were found. We also tried pressing the reset and select buttons at random times when they were not supposed to do anything during the cycle and that as well did not bring upon any problems. We did not do any moisture level testing or water resistance tests because we did not want to ruin our project and that is to certainly bring issues. Overall, for what the system is built to do, it seems to be very robust and can do the tasks effectively.







 

 











 










