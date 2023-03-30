# On_demand_traffic_light_control_ATmega32-Embedded_Professional_Degree-Udacity_egFWD
Implement a traffic lights system with an on-demand crosswalk button using Atmel Studio and Proteus Simulation.
An Embedded system, Developed In C Programming Language, It controls the street flow Between Cars and Pedestrians. 
<h3 align="left">The System Main Components are:</h3>
ATMega32 Microcontroller, 6 LEDs, Push Button. The Drivers That implemented and used is: GPIO, Timer, External Interrupt, LED.
The Application have 2 Modes :
1-Normal Mode:
The System Starts by Cars Green LED and Pedestrians Red LED is ON for 5 seconds and the remaining LEDs is OFF, Then Cars and Pedestrians Yellow LEDs is Blinking for 5 seconds and and the remaining LEDs is OFF, Then Cars Red LED and Pedestrians Green LED is ON for 5 seconds and the remaining LEDs is OFF, then yellow LEDs Blinking for 5 seconds , Then Return To The Start Point.
2- Pedestrian Mode:
There Is A restriction of using the Pedestrian Button: If The Pressing Time is more Than 1.5 seconds, the system will not take any action.
<When a Pedestrian Push The Button, The System will take Action in the following cases and change the program flow:
- If Cars Green LED is ON, Then the System will immediately change the current active LEDs to the case of Yellow LEDs Blinking For 5 seconds, Then Turn ON the Cars Red LED and the Pedestrian Green LED.
- If The current active LEDs is yellow and The next Active LED is the Cars Green LED, Then the system change the flow to the case of Yellow LEDs Blinking For 5 seconds, Then Turn ON the Cars Red LED and the Pedestrian Green LED.
else the system will not take actions.
