# Final-Project: Automatic Fish Tank Feeder
BAE305 Final Project
* Eli Barrow
* Alexis Puckett
* Hannah Markwell

## Summary:

Our BAE305 project is for an aquarium monitoring and feeding system. The system includes an automatic feeder that is on a timer for periods of 6 hours, 12 hours, and 24 hours, and it distributes food directly to the fish in the tank. The feeder uses an auger and stepper motor to push the fish food out of the container, into the fish tank. Our project also includes a mechanism that reads the temperature, displays it, and then turns on a red LED if the temperature falls below a specified point, and a green LED if the temperature is good for the safety of the fish. It also includes a feature that monitors the water level of the fish tank, and this feature turns on an LED to alert low water levels in the tank. Our display system displays the red and green LEDs for both the temperature and water level monitoring systems. It also has two screens, one to show the temperature and water level data, and one to show how much time is left until the next feeding. We used a potentiometer for the user to change the feeding time from 6, 12, and 24 hours. Finally, our display has two potentiometers to control the contrast of the screens. Both the feeder and display systems are 3D printed.

## Design Description

 Materials:
 *

 Design:

 Circuits:
For our project, we used two seperate Arduinos to run everything. One Arduino controlled the temperature and water level system and the other controlled the feeder system. These Arduinos are not in communication with eachother. We thought this would be best in order to simplify the code, and if one system failed to work, the other one could still work.

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/Monitoring%20System%20Documents/Temp%20%26%20Water%20Level%20Circuit/Schematics/Screenshot%202024-04-06%20at%2011.44.04%20AM.png">
</p>

<p align="center">
  <img src="https://github.com/elibarrow/Final-Project/blob/main/Feeding%20System%20Documents/Final%20Code%20for%20Feeder%20%26%20LCD/Schematics/Image%20of%20Schematic.png">
</p>

 Code:

 Assembly:

 

## Test Description

## Design Decision Discussion

## Results
