#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int MAX_ROW = 30;
const int MAX_COL = 60;
const int PATTERN_HEIGHT = 6;
const int PATTERN_WIDTH = 7;

void displayMenu();
void setZeroArray(int array[MAX_ROW][MAX_COL]);
void setInitialPatternArray(int array[MAX_ROW][MAX_COL]);
void copyArray(const int fromArray[MAX_ROW][MAX_COL], int toArray[MAX_ROW][MAX_COL]);
void displayArray(const int array[MAX_ROW][MAX_COL]);

int main()
{
    char option;
    int currentArray[MAX_ROW][MAX_COL];
    int tempArray[MAX_ROW][MAX_COL];
    
    srand(time(NULL)); // Seed the number generator
    
    do
    {
        displayMenu();
        setZeroArray(tempArray);
        setInitialPatternArray(tempArray);
        copyArray(tempArray, currentArray);
        displayArray(currentArray);
        
        cout << ">> ";
        cin >> option;
    }while(tolower(option) == 'p');
    
    return 0;
}

void displayMenu()
{
    cout <<
        "[P]lay – Press 'P' to play.\n"
        "[Q]uit – Press 'Q' to exit.\n"
        "\n";
}

void setZeroArray(int array[MAX_ROW][MAX_COL])
{
    for(int coordX = 0; coordX < MAX_ROW; coordX++)
    {
        for(int coordY = 0; coordY < MAX_COL; coordY++)
        {
            array[coordX][coordY] = 0;
        }
    }
}

void setInitialPatternArray(int array[MAX_ROW][MAX_COL])
{
    int startRow = rand() % (MAX_ROW - PATTERN_HEIGHT);
    int startCol = rand() % (MAX_COL - PATTERN_WIDTH);
    // Set the two vertical lines
    for(int len = 0; len < PATTERN_HEIGHT; len++)
    {
        array[startRow + len][startCol] = 1;
        array[startRow + len][startCol + (PATTERN_WIDTH - 1)] = 1; // For the second side of the pattern
    }
    // Set the horizontal line at the bottom
    for(int len = 0; len < PATTERN_WIDTH; len++)
    {
        array[startRow + (PATTERN_HEIGHT - 1)][startCol + len] = 1;
    }
}

void copyArray(const int fromArray[MAX_ROW][MAX_COL], int toArray[MAX_ROW][MAX_COL])
{
    for(int coordX = 0; coordX < MAX_ROW; coordX++)
    {
        for(int coordY = 0; coordY < MAX_COL; coordY++)
        {
            toArray[coordX][coordY] = fromArray[coordX][coordY];
        }
    }
}

void displayArray(const int array[MAX_ROW][MAX_COL])
{
    for(int coordX = 0; coordX < MAX_ROW; coordX++)
    {
        for(int coordY = 0; coordY < MAX_COL; coordY++)
        {
            cout << array[coordX][coordY];
        }
        cout << "\n";
    }
}