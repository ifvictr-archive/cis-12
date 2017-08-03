#include <cstdlib>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int MAX_ROW = 30;
const int MAX_COL = 60;
const int PATTERN_HEIGHT = 6;
const int PATTERN_WIDTH = 7;

void displayMenu();
void displayArray(const int array[MAX_ROW][MAX_COL]);
void copyArray(const int fromArray[MAX_ROW][MAX_COL], int toArray[MAX_ROW][MAX_COL]);
void setZeroArray(int array[MAX_ROW][MAX_COL]);
void setInitialPatternArray(int array[MAX_ROW][MAX_COL]);
void setNextGenArray(const int fromArray[MAX_ROW][MAX_COL], int toArray[MAX_ROW][MAX_COL]);

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
        while(true)
        {
            system("cls");
            if(kbhit())
            {
                break;
            }
            else
            {
                setNextGenArray(currentArray, tempArray);
                copyArray(tempArray, currentArray);
                displayArray(currentArray);
                Sleep(1000);
            }
        }
        option = getch();
    }while(option != 'q');
    
    return 0;
}

void displayMenu()
{
    cout <<
        "[P]lay - Press 'P' to play.\n"
        "[Q]uit - Press 'Q' to exit.\n"
        "\n";
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

void setNextGenArray(const int fromArray[MAX_ROW][MAX_COL], int toArray[MAX_ROW][MAX_COL])
{
    for(int coordX = 0; coordX < MAX_ROW; coordX++)
    {
        for(int coordY = 0; coordY < MAX_COL; coordY++)
        {
            int alive = 0;
            // Top-left corner
            if((coordX == 0) && (coordY == 0))
            {
                if(fromArray[0][1] == 1)
                    alive++;
                if(fromArray[1][1] == 1)
                    alive++;
                if(fromArray[1][0] == 1)
                    alive++;
            }
            // Top-right corner
            else if((coordX == 0) && (coordY == (MAX_COL - 1)))
            {
                if(fromArray[0][MAX_COL - 2] == 1)
                    alive++;
                if(fromArray[1][MAX_COL - 2] == 1)
                    alive++;
                if(fromArray[1][MAX_COL - 1] == 1)
                    alive++;
            }
            // Bottom-left corner
            else if((coordX == (MAX_ROW - 1)) && (coordY == 0))
            {
                if(fromArray[MAX_ROW - 1][1] == 1)
                    alive++;
                if(fromArray[MAX_ROW - 2][1] == 1)
                    alive++;
                if(fromArray[MAX_ROW - 2][0] == 1)
                    alive++;
            }
            // Bottom-right corner
            else if((coordX == (MAX_ROW - 1)) && (coordY == (MAX_COL - 1)))
            {
                if(fromArray[MAX_ROW - 1][MAX_COL - 2] == 1)
                    alive++;
                if(fromArray[MAX_ROW - 2][MAX_COL - 2] == 1)
                    alive++;
                if(fromArray[MAX_ROW - 2][MAX_COL - 1] == 1)
                    alive++;
            }
            // Top edge
            else if(coordX == 0)
            {
                if(fromArray[0][coordY - 1] == 1)
                    alive++;
                if(fromArray[1][coordY - 1] == 1)
                    alive++;
                if(fromArray[1][coordY] == 1)
                    alive++;
                if(fromArray[1][coordY + 1] == 1)
                    alive++;
                if(fromArray[0][coordY + 1] == 1)
                    alive++;
            }
            // Bottom edge
            else if(coordX == (MAX_ROW - 1))
            {
                if(fromArray[MAX_ROW - 1][coordY - 1] == 1)
                    alive++;
                if(fromArray[MAX_ROW - 2][coordY - 1] == 1)
                    alive++;
                if(fromArray[MAX_ROW - 2][coordY] == 1)
                    alive++;
                if(fromArray[MAX_ROW - 2][coordY + 1] == 1)
                    alive++;
                if(fromArray[MAX_ROW - 1][coordY + 1] == 1)
                    alive++;
            }
            // Left edge
            else if(coordY == 0)
            {
                if(fromArray[coordX - 1][0] == 1)
                    alive++;
                if(fromArray[coordX - 1][1] == 1)
                    alive++;
                if(fromArray[coordX][1] == 1)
                    alive++;
                if(fromArray[coordX + 1][1] == 1)
                    alive++;
                if(fromArray[coordX + 1][0] == 1)
                    alive++;
            }
            // Right edge
            else if(coordY == (MAX_COL - 1))
            {
                if(fromArray[coordX - 1][MAX_COL - 1] == 1)
                    alive++;
                if(fromArray[coordX - 1][MAX_COL - 2] == 1)
                    alive++;
                if(fromArray[coordX][MAX_COL - 2] == 1)
                    alive++;
                if(fromArray[coordX + 1][MAX_COL - 2] == 1)
                    alive++;
                if(fromArray[coordX + 1][MAX_COL - 1] == 1)
                    alive++;
            }
            // Away from all edges
            else
            {
                if(fromArray[coordX - 1][coordY - 1] == 1)
                    alive++;
                if(fromArray[coordX - 1][coordY] == 1)
                    alive++;
                if(fromArray[coordX - 1][coordY + 1] == 1)
                    alive++;
                if(fromArray[coordX][coordY + 1] == 1)
                    alive++;
                if(fromArray[coordX + 1][coordY + 1] == 1)
                    alive++;
                if(fromArray[coordX + 1][coordY] == 1)
                    alive++;
                if(fromArray[coordX + 1][coordY - 1] == 1)
                    alive++;
                if(fromArray[coordX][coordY - 1] == 1)
                    alive++;
            }
            // Check rules
            if(fromArray[coordX][coordY] == 1)
            {
                if((alive == 2) || (alive == 3))
                {
                    toArray[coordX][coordY] = 1;
                }
                // Died from overpopulation/underpopulation
                else
                {
                    toArray[coordX][coordY] = 0;
                }
            }
            else
            {
                // Born from reproduction
                if(alive == 3)
                {
                    toArray[coordX][coordY] = 1;
                }
                else
                {
                    toArray[coordX][coordY] = 0;
                }
            }
        }
    }
}