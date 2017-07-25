Write a C++ program that tests the function main and the functions discussed in parts 1 through 7. (Add additional functions, such as printing a two-dimensional array, as needed.).

Consider the following function main:

int main()
{
     int inStock[10][4];
     int alpha[20];
     int beta[20];
     int gamma[4] = {11, 13, 15, 17};
     int delta[10] = {3, 5, 2, 6, 10, 9, 7, 11, 1, 8};
     .
     .
}


1. Write the definition of the function setZero that initializes any one-dimensional array of type int to 0 (alpha and beta).

2. Write the definition of the function inputArray that prompts the user to input 20 numbers and stores the numbers into alpha.

3. Write the definition of the function doubleArray that initializes the elements of beta to two times the corresponding elements in alpha.  Make sure that you prevent the function from modifying the elements of alpha.

4. Write the definition of the function copyGamma that sets the elements of the first row of inStock from gamma and the remaining rows of inStock to three times the previous row of inStock.  Make sure that
you prevent the function from modifying the elements of gamma.

5. Write the definition of the function copyAlphaBeta that stores alpha into the first five rows of inStock and beta into the last five rows of inStock.  Make sure that you prevent the function from modifying the
elements of alpha and beta.

6. Write the definition of the function printArray that prints any one-dimensional array of type int.  

7. Write the definition of the function setInStock that prompts the user to input the elements for the first column of inStock.  The function should then set the elements in the remaining columns to two times the
corresponding element in the previous column, minus the corresponding element in delta.

 

 

***Do not use any pre-defined functions that were not covered in the class.

***Use only topics that were covered in the class.

***No object-oriented programming.

***Match the output below (OUTPUTS section).

 

Submit your source code (file name is Assignment18_yourLastName.cpp).  Make sure that it compiles using Code::Blocks.

If it doesn't compile, you will lose 50%.  Improper indentation: -20%

If it doesn't produce the required results: -30%.  Formatting output: -20%

Do NOT compress the file.

 

**************************************************************************************

OUTPUTS: 

Sample Output (Use the tab between numbers.):

**************************************************************************************

 

Alpha after initialization
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
***********************************************

Enter 20 integers
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20


Alpha after reading 20 numbers
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
***********************************************

Beta after a call to doubleArray
2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40
***********************************************

inStock after a call to copyGamma
11 13 15 17
33 39 45 51
99 117 135 153
297 351 405 459
891 1053 1215 1377
2673 3159 3645 4131
8019 9477 10935 12393
24057 28431 32805 37179
72171 85293 98415 111537
216513 255879 295245 334611
***********************************************

inStock after a call to copyAlphaBeta
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
17 18 19 20
2 4 6 8
10 12 14 16
18 20 22 24
26 28 30 32
34 36 38 40
***********************************************

Enter 10 integers
21
22
23
24
25
26
27
28
29
30


inStock after a call to setInStock
21 39 75 147
22 39 73 141
23 44 86 170
24 42 78 150
25 40 70 130
26 43 77 145
27 47 87 167
28 45 79 147
29 57 113 225
30 52 96 184
***********************************************