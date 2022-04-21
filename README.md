# parkingSystem

hey it's naman bansal

->help.cpp is used to generate input file and parkinghelp.cpp file is used to add 96 entries in the system
->the order of running file is:
  help.cpp ->generates input.txt
  parkinghelp.cpp adds the inputs in system
  parking.cpp

->this is a low level parking system design where 100 cars can be parked.

->the parking.txt file is used to store the entered cars with registration number and time and date entered.

->on removal of the car with the help of registration number the time for with the car was parked is displayed.

->the status of the parking lot can be viewed

->constructor is used to initialize the spots array which containes information about cars parked

->currcars is used to count number of cars andlastpark is used to determine the last car parked in order to minimize traversal.

->on exit all the entries are written into the parking.txt file that is loaded on start of program
