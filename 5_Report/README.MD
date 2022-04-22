# EVALUATING CODE FOR LCD AND DATA ACQUISITION
To integrate an LCD with AVR microcontroller that can be display a string of characters using hexadecimal data values.Implement a program code for ATMEGA328P to display the numbers 0-9 lon the 16X2 LCDdisplay using keypad.

## Folder Structure

|Folder|Description|
|------|-----------|
|1_Requirements|Documents Detailing requirements and research|
|2_Design|Documents Specifying design details|
|3_Implementation|All Code and Documentation|
|4_Testplan and output|Output|

## Functions

|Feature Id|Feature|
|----------|-------|
|F_01|addition,subraction,multiplication,division|
|F_02|Displaying in 16X2 LCD|

## Challenges Faced and How Was It Overcome

|No.|Challenge|Solution|
|---|---------|--------|
|1.|On the simulide latest version some sources are not available|By the help of connect class solved|
|2.|issues in implementation|fixed them by making template in order|
|3.|Issues in workflows|fixed them by updating the path to all files correctly|

## HIGH LEVEL REQUIREMENTS


*Test ID* | *Description*                                              | *Exp I/P* | *Exp O/P* | *Actual O/P* |*Type Of Test*  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |lcd             |  Valid I/P  |Valid O/P|Valid O/P|Scenario based |
|  H_02       |  single number                            |  Invalid I/P|Program termination|Program termination | based    |
|  H_03       | add or sub                                    |  Invalid choice I/P|Wrong choice.Please choose again|Wrong choice.Please choose again|Scenario based    |
|  H_04       |   using like calci                                   |  Valid I/P|Valid O/P|Valid O/P|Scenario based |



## Low level Requriments

| *Test ID* | *Description*                                              | *Exp I/P* | *Exp O/P* | *Actual O/P* |*Type Of Test*  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |   ATMEGA 328                                                   |  Integer value|Valid o/p|Valid o/p|Scenario based unit testing |
|  L_02     |                  AVR GCC compiler                                |  Integer value|Valid o/p|Valid o/p|Scenario based unit testing   |
|  L_03       |          Simulide                              |  Integer value|Valid o/p|Valid o/p|Scenario based unit testing    |
