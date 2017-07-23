Write a C++ program that computes the cost of a long-distance call.

The cost of the call is determined according to the following rate schedule:

     a. Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a rate of $0.40 per minute.

     b. Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged at a rate of $0.25 per minute.

     c. Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.

The input will consist of the day of the week, the time the call started, and the length of the call in minutes. The output will be the cost of the call. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as (must be the following format:)
13:30

The day of the week will be read as one of the following pairs of character values, which are stored in two variables of type char:
Mo Tu We Th Fr Sa Su

Be sure to allow the user to use either uppercase or lowercase letters or a combination of the two. The number of minutes will be input as a value of type int.  

Format your output to two decimal places.

 

Define the following functions (value returning functions, Cally-by-Value):

validateUserInputTime(): validates the user's time input (hours and minutes should be positive numbers only including zero), and returns TRUE or FALSE.

validateUserInputDay(): validates the user's day input (only characters are allowed: Mo Tu We Th Fr Sa Su), and returns TRUE or FALSE.  Allow uppercase and lowercase input.

validateUserInputCallLength(): validates the user's call length input (only positive integers are allowed), and returns TRUE or FALSE.

calculateTotalCost(): calculate the total cost of a call, and returns the total cost.

 

 

***Collect the user's inputs in the main() and pass them to  the other functions.

***Allow the user to repeat the program.

***Do not use any pre-defined functions that were not covered in the class.

***Use only topics that were covered in the class.

***No object-oriented programming.

***Match the output below (OUTPUTS section).

 

 

Submit your source code (file name is Assignment14_yourLastName.cpp).  Make sure that it compiles using Code::Blocks.

If it doesn't compile, you will lose 50%.  Improper indentation: -20%

If it doesn't produce the required results: -30%

Do NOT compress the file.

 

**************************************************************************************

OUTPUTS:

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
-13:10

Invalid time input.

Please try again.

 

Enter the time the call starts in 24-hour rotation:

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
a:77

Invalid time input.

Please try again.

 

Enter the time the call starts in 24-hour rotation:

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
13:10

Enter the first two letters of the day of the week:
ss

Invalid day input.

Please try again.

 

Enter the first two letters of the day of the week:

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
13:10

Enter the first two letters of the day of the week:
1s

Invalid day input.

Please try again.

 

Enter the first two letters of the day of the week:

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
13:10

Enter the first two letters of the day of the week:
Mo

Enter the length of the call in minutes:
-10

Invalid minute input.

Please try again.

 

Enter the length of the call in minutes:

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
13:10

Enter the first two letters of the day of the week:
Mo

Enter the length of the call in minutes:
a1

Invalid minute input.

Please try again.

 

Enter the length of the call in minutes:

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
13:10

Enter the first two letters of the day of the week:
Mo

Enter the length of the call in minutes:
10

Cost of the call: $4.00


Do you want to repeat the program?
y

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
20:10

Enter the first two letters of the day of the week:
Fr

Enter the length of the call in minutes:
10

Cost of the call: $2.50


Do you want to repeat the program?
y

**************************************************************************************

Enter the time the call starts in 24-hour rotation:
10:10

Enter the first two letters of the day of the week:
Su

Enter the length of the call in minutes:
10

Cost of the call: $1.50


Do you want to repeat the program?
n

**************************************************************************************