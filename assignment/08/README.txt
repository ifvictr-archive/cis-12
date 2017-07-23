Write a C++ program that mimics a calculator. 

The program should take as input two integers and the operation to be performed.

Sample user inputs:

3 + 4

10 - 5

2 * 4

4 / 2

 

It should then output the numbers, the operator, and the result. (For division, if the denominator is zero, output an appropriate message: "Cannot divide by zero")

Sample outputs:

3 + 4 = 7

10 - 5 = 5

2 * 4 = 8

4 / 2 = 2

 

***Use switch statement for operators (+, -, *, /). If the user types a different operator, prompt the user: "Illegal Operation", and terminate the program.)

 

***Use the main function only.

***You assume that the user types only integer numbers.

***Do not use any pre-defined functions except ones that were covered in the class.

***Use only topics that were covered in the class.

***No object oriented programming.

***Match the output below (OUTPUT section).

 

Submit your source code (file name is Assignment08_yourLastName.cpp). Make sure that it compiles using Code::Blocks.

If it doesn't compile, you will lose 50%. Improper indentation: -20%

If it doesn't produce the required results: -30%

Do NOT compress the file.

 

**********************************************************************

OUTPUT:

**********************************************************************

Enter two integer numbers with an arithmetic operator (ex. 3 + 4):
3 + 4

3 + 4 = 7

**********************************************************************

Enter two integer numbers with an arithmetic operator (ex. 3 + 4):
10 - 5

10 - 5 = 5

**********************************************************************

Enter two integer numbers with an arithmetic operator (ex. 3 + 4):
2 * 4

2 * 4 = 8

**********************************************************************

Enter two integer numbers with an arithmetic operator (ex. 3 + 4):
4 / 2

4 / 2 = 2

**********************************************************************

Enter two integer numbers with an arithmetic operator (ex. 3 + 4):
3 % 2

Illegal Operation.

**********************************************************************

Enter two integer numbers with an arithmetic operator (ex. 3 + 4):
3 / 0

Can't divide by 0.

**********************************************************************