You will add the followings to the Gol_Project-Part2_yourLastName.cpp file.

1. Change the size of the arrays:

     const int MAX_ROW = 40;
     const int MAX_COL = 80;

   ***Make sure that only global variables you have in your program are Max_ROW and MAX_COL.  Move any global variables you declared to a function or functions.

   ***Make sure to update setNextGenArray().  Use the variable names, not 40 or 80.

   ***For testing, I will be changing the array size.  Your program should work by only modifying the array size.



2. Use two-dimensional arrays (tempArray, currentArray) of type char, instead of type int.

3. Choose a character for live cells, and a character for dead cells.

4. When you start your program, it should display only dead cells.

5. Modify the menu to include the followings (you may change the menu and descriptions, but must contain all the following options):

Initial - 'I' to load the 'U' pattern.

Play - 'P' to play the game.

Stop - 'S' to stop the game.

Clear - 'C' to set the arrays to the dead cells.

Quit - 'Q' to exit the program

1) pattern1 name - '1' to load the pattern1.txt file to the screen.  (Replace pattern1 name with an actual pattern name you have, ex: 1) spaceship ).  The location of the loaded pattern should be randomized.

2) pattern2 name - '2' to load the pattern2.txt file to the screen.  (Replace pattern2 name with actual pattern name you have, ex: 2) snake ).   The location of the loaded pattern should be randomized.

3) pattern3 name - '3' to load the pattern3.txt file to the screen.  (Replace pattern3 name with actual pattern name you have, ex: 3) phython ).   The location of the loaded pattern should be randomized.

Custom - 'T' to create a pattern from the user's input (collect row and column numbers) and set each cell to a live cell.

Save - 'A' to save the current live cell pattern of the currentArray to a file; save the row and column numbers of the live cells.  (You may allow the user to type a file name.)

Load - 'L' to load a saved file. (You may allow the user to type the file name the user wish to load.)



***Allow the user to type uppercase or lowercase characters.



6. Add three more patterns except the 'U' pattern.  See the file below (do not use block and tub), or you may create your own patterns.   Present the different patterns (at least 3 using files - pattern1.txt, pattern2.txt, pattern3.txt) to the user in the menu (see 5), then allow the user to load those files; create a function to access each file (pass filename as a parameter to the function).  Each file contains the row and column numbers of live cells.

Game_of_Life_Patterns.png





7. You may create additional variables and functions as necessary. (Name them properly)

     ****When declaring variables and functions, use a meaningful name; don't just use x, y, a, b, etc.  Don't just use a single character. (-30 points)



***Do not use any pre-defined functions that were not covered in the class.

***Use only topics that were covered in the class.

***No object-oriented programming.



Submit your source code (file name is GoL_Project-Part3_yourLastName.cpp) and the three text files: create a folder called GOL_yourLastName, put all the files into the folder, compress the folder, and submit the compressed file.  If you submit a 100% working version by the deadline, I will give you extra credit (20 points).



Make sure that it compiles using Code::Blocks.

If it doesn't compile, you will lose 50%. Improper indentation: -20%

If it doesn't produce the required results: -30%



**************************************************************************************

OUTPUTS:

**************************************************************************************



GOL_Part3.zip

The above file is to show an expected outcome, serving as an example.  It is still using 30x60 array size.  The pattern 2 and 3 are not working, because the zip file doesn't contain the files for 2 and 3.

**************************************************************************************