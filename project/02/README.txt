You will add the followings to the Gol_Project-Part1_yourLastName.cpp file.

1. Use the global variables properly:


     const int MAX_ROW = 30;

     const int MAX_COL = 60;

     for example:

     int currentArray[MAX_ROW][MAX_COL];

     instead of  int currentArray[30][60];

     ****In your program, replace '60' with MAX_COL and replace '30' with MAX_ROW.

     ****When declaring variables, array names, use a meaningful name; don't just use x, y, a, b, etc.  Don't just use a single character. (-30 points)

 

2. Write the definition of the function setNextGenArray that creates a pattern of next generation (tempArray) based on the current generation (currentArray); modify the tempArray based on the currentArray by applying the rules of Game of Life.

Conway's Game of Life Rules:

- The neighbors of a given cell are the cells that touch it vertically, horizontally, or diagonally.
- Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

 

3. Create a loop to generate and next pattern automatically.

When executing your program, the following should happen:
     a. Print the menu using the displayMenu function.
     b. Initialize the tempArray using the setZeroArray function.
     c. Set the ‘U’ pattern in the tempArray using the setInitialPatternArray function.
     d. Copy the tempArray to the currentArray using the copyArray function.
     e. Print the currentArray using the displayArray function.
     f. When the user presses ‘P’, (loop the following three steps)
          i. Generate a next pattern using the setNextGenArray function
          ii. Copy the tempArray to the currentArray using the copyArray function.
          iii. Print the currentArray using the displayArray function.
     g. When the user presses ‘Q’, it will terminate the program.

 

Sample loop:

GameofLife_Loop_Sample.txt

 

 

***Do not use any pre-defined functions that were not covered in the class.

***Use only topics that were covered in the class.

***No object-oriented programming.

 

Submit your source code (file name is GoL_Project-Part2_yourLastName.cpp).

Make sure that it compiles using Code::Blocks.

If it doesn't compile, you will lose 50%. Improper indentation: -20%

If it doesn't produce the required results: -30%

Do NOT compress the file.

 

**************************************************************************************

OUTPUTS: 

**************************************************************************************

GoL_Project-Part2.exe

**************************************************************************************