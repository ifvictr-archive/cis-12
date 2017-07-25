Write a C++ program that accepts a year written as a four-digit Arabic (ordinary) numeral and outputs the year written in Roman numerals.

Important:
Roman numerals are V for 5, X for 10, L for 50, C for 100, D for 500, and M for 1,000.

Recall that some numbers are formed by using a kind of subtraction of one Roman “digit”; for example, IV is 4 produced as V minus I, XL is 40, CM is 900, and so on.

A few sample years: MCM is 1900, MCML is 1950, MCMLX is 1960, MCMXL is 1940, MCMLXXXIX is 1989.

(Hints: Use division and mod.)

 

Assume the year is between 1000 and 3000.  Prompt the user again if the user types less than 1000 or bigger than 3000.

Your program should include a loop that lets the user repeat this calculation until the user says she or he is done.

 

Define the following functions (value returning functions, Cally-by-Reference):

validateUserInput(): validates the user's input (must be between 1000 and 3000, and integers only).

returnRomanThousandsPlace(): returns roman numerals for the thousand place.

returnRomanHundredsPlace(): returns roman numerals for the hundreds place.

returnRomanTensPlace(): returns roman numerals for the tens place.

returnRomanOnesPlace(): returns roman numerals for the ones place.

 

***Collect the user's inputs in the main() and pass them to  the other functions.

***Validate the user's inputs.

***Allow the user to repeat the program.

 

***Do not use any pre-defined functions that were not covered in the class.

***Use only topics that were covered in the class.

***No object-oriented programming.

***Match the output below (OUTPUTS section).

 

Submit your source code (file name is Assignment16_yourLastName.cpp).  Make sure that it compiles using Code::Blocks.

If it doesn't compile, you will lose 50%.  Improper indentation: -20%

If it doesn't produce the required results: -30%.  Formatting output: -20%

Do NOT compress the file.

 

**************************************************************************************

OUTPUTS:

**************************************************************************************

This program will accept a year written in four digit ordinary numeral and will
convert it into roman numerals.

Enter a year between 1000 and 3000:
5000


The year entered is invalid. Enter a valid year between 1000 to 3000:
1952

Your number in roman numerals is: MCMLII


Do you want to repeat the program again? y or n
y

**************************************************************************************

This program will accept a year written in four digit ordinary numeral and will
convert it into roman numerals.


Enter a year between 1000 and 3000:
2048

Your number in roman numerals is: MMXLVIII


Do you want to repeat the program again? y or n
y

**************************************************************************************

This program will accept a year written in four digit ordinary numeral and will
convert it into roman numerals.


Enter a year between 1000 and 3000:
2500

Your number in roman numerals is: MMD


Do you want to repeat the program again? y or n
n
**************************************************************************************