# Final-Project: Automatic Fish Tank Feeder
***BAE305 Final Project***
* Eli Barrow
* Alexis Puckett
* Hannah Markwell

## Summary:

Our BAE305 project is for an aquarium monitoring and feeding system. The system includes an automatic feeder that is on a timer for periods of 6 hours, 12 hours, and 24 hours, and it distributes food directly to the fish in the tank. The feeder uses an auger and stepper motor to push the fish food out of the container, into the fish tank. Our project also includes a mechanism that reads the temperature, displays it, and then turns on a red LED if the temperature falls below a specified point, and a green LED if the temperature is good for the safety of the fish. It also includes a feature that monitors the water level of the fish tank, and this feature turns on an LED to alert low water levels in the tank. Our display system displays the red and green LEDs for both the temperature and water level monitoring systems. It also has two screens, one to show the temperature and water level data, and one to show how much time is left until the next feeding. We used a potentiometer for the user to change the feeding time from 6, 12, and 24 hours. Finally, our display has two potentiometers to control the contrast of the screens. Both the feeder and display mechanical systems are 3D printed.

## Design Description

 **Materials:**  
 For this project the materials needed are simple electrical components as well as the ability to access a 3D printer to print the larger mechanical parts of the system.
 The electrical components needed are:
 - 2 Arduino Uno Boards with Breadboards
 - Ability to connect the Uno to your computer
 - Approx. 50 wires that're compatable with the Arudino, Breadboard, and components
 - 2 LCD Screens
 - 1 5V DC Stepper Motor (ROHS 28byj-48)
 - 3 Potentiometers
 - 2 Push buttons
 - 2 Green LEDs
 - 2 Red LEDs
 - 1 Float Switch
 - 1 Thermistor
 - 4 1kOhm Resistors
 - 1 10kOhm Precision Resistor (for thermistor)
 - 3 10 kOhm Resistor
 

 **Physical Design:**   

The design of the feeding system was a small hopper with an auger in the bottom of it that would be turned by a stepper motor to slowly push the food out of the front of the hopper body. There is a hole that runs from the back of the hopper body to the front of the hopper body where the auger slides into, with a stop being placed on the front side that does not allow the auger to slide all the way through. Below this stop is the funnel shape that the food will slide down into the tank to reach the fish. The base of the auger is specially designed to allow the shaft of the stepper motor to mate into the auger, connecting the two for a smooth rotational motion. The stepper motor came with a screw mounting bracket on each side, we then measured the size of those holes with calipers then created two extrusions on the back side of the hopper that would be used to mount the stepper motor. Then finally for a flush fit of the auger with the back wall of the hopper body some spacers were needed to be put on the shaft to create the proper offset of the stepper motor. The type of food that is normally given to the fish is very small spherical pellets that would almost flow fluidly in a system like this, so this design is what the team moved forward with. There was also a need for the hopper to be mounted to the back glass of the fish tank since there is no spot for the hopper to sit on top of the lid, so the team designed a bracket that mounts to the back glass of the tank for the hopper/feeding system to sit on. The design drawings of the Hopper, Bracket, Auger, and Spacers are shown below, as well as links to the online design file through OnShape, where the .stl files can be exported for 3D printing purposes.

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Feeder/Feeder/Hopper.png" width = 50%><img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Feeder/Auger%20%26%20HexSpacer/Auger.png" width = 50%>
</p>

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Feeder/Feeder%20Bracket/HOPPER%20STAND.png" width = 50%><img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Feeder/Assembly/Feeding%20Assembly.png" width = 50%>
</p>

**Link for Onshape Feeder Files:**
https://cad.onshape.com/documents/4df08dd93363a5b6d688b396/w/b2cb09403d87c3bcf0b51dba/e/0a122a04bef23e0f82b38aa6?renderMode=0&uiState=6621793480254631186acf1b


 After designing the Feeding system there was also a need to mount the thermistor and float switch to the back glass of the fish tank alongside the feeder. This only needed a few measurements taken of the float switch diameter and thermistor wire diameter to make a simple bracket, similar to the hopper bracket. The drawing file is shown below and is accomanied with a link to OnShape.


<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/3d%20Printed%20Files/Temp%26Float%20Switch%20Bracket/Float%20Switch%20Bracket%20Drawing.png" width = 50%>
</p>


**Link for Onshape Float Switch & Thermistor Bracket Files:**   
https://cad.onshape.com/documents/ca7b3c8a11bfe362b02dd540/w/57267339f03928a64975b33e/e/b6ae37b48c85a3c1fea425d9?renderMode=0&uiState=6621795a283cfb13c7dd5678

 

 **Circuits:**
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

 Code:

 Assembly:

 

## Test Description

## Design Decision Discussion

The design of this system was purely driven by one of the group member's experience with being away from a fishtank at their home for an extended period of time and not being able to feed their fish. After the group began considering this, the others then added some other features to add to the system, rather than just making a fish feeder. This ultimatley lead the group to pursue a design that included an automatic feeder, water temperature monitor and a water level monitor. The mechanical design of the project was strictly driven by the constraits that were presented by the fish tank that it was being designed for. The fish tank did not have a viable place for a feeder to sit on the lid, but there is an opening in the backside of the lid that would allow for the feeder to be attached to the glass, as well as the addition of a temperature sensor and water level sensor. Since this project had a budget of $0 we chose materials that were very cheap and used online software that is free to use, such as OnShape and TinkerCAD.

## Results













 

 











 










