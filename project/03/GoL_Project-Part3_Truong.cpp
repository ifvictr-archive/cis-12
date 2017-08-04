#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const char CELL_DEAD = '-';
const char CELL_ALIVE = 'O';
const int MAX_ROW = 40;
const int MAX_COL = 80;
const int PATTERN_HEIGHT = 6;
const int PATTERN_WIDTH = 7;

void loadFromFile(string filename, char array[MAX_ROW][MAX_COL], bool randomize);
void saveToFile(string filename, const char array[MAX_ROW][MAX_COL]);
void displayMenu();
void displayArray(const char array[MAX_ROW][MAX_COL]);
void copyArray(const char fromArray[MAX_ROW][MAX_COL], char toArray[MAX_ROW][MAX_COL]);
void setZeroArray(char array[MAX_ROW][MAX_COL]);
void setInitialPatternArray(char array[MAX_ROW][MAX_COL]);
void setNextGenArray(const char fromArray[MAX_ROW][MAX_COL], char toArray[MAX_ROW][MAX_COL]);

int main()
{
    bool loop = true;
    char option;
    char currentArray[MAX_ROW][MAX_COL];
    char tempArray[MAX_ROW][MAX_COL];

    srand(time(NULL)); // Seed the number generator

    displayMenu();
    setZeroArray(tempArray);
    copyArray(tempArray, currentArray);
    displayArray(currentArray);
    do
    {
        while(true)
        {
            // Stop if no option yet or if it's 's'
            if(kbhit() || !option || (option == 's'))
            {
                break;
            }
            else
            {
                system("cls");
                copyArray(tempArray, currentArray);
                displayArray(currentArray);
                switch(option)
                {
                    case '1':
                        if(!loop) break;
                        loadFromFile("pattern1", tempArray, true);
                        loop = false;
                        break;
                    case '2':
                        if(!loop) break;
                        loadFromFile("pattern2", tempArray, true);
                        loop = false;
                        break;
                    case '3':
                        if(!loop) break;
                        loadFromFile("pattern3", tempArray, true);
                        loop = false;
                        break;
                    case 'a':
                        {
                            if(!loop) break;
                            string filename;
                            cout << "Choose a name for your save file (do not include extension): ";
                            cin >> filename;
                            saveToFile(filename, currentArray);
                            loop = false;
                        }
                        break;
                    case 'c':
                        if(!loop) break;
                        setZeroArray(tempArray);
                        loop = false;
                        break;
                    case 'i':
                        if(!loop) break;
                        setInitialPatternArray(tempArray);
                        loop = false;
                        break;
                    case 'l':
                        {
                            if(!loop) break;
                            string filename;
                            cout << "Enter save file's name (do not include extension): ";
                            cin >> filename;
                            setZeroArray(tempArray); // Wipe the current grid
                            loadFromFile(filename, tempArray, false);
                            loop = false;
                        }
                        break;
                    case 'p':
                        setNextGenArray(currentArray, tempArray);
                        loop = true;
                        break;
                    case 'q':
                        exit(0);
                    case 't':
                        {
                            if(!loop) break;
                            int coordX;
                            int coordY;
                            cout << "Enter all the coordinates you want to spawn cells on by typing [your x coord] [space] [your y coord] [enter]. Type a non-numeric character when you're done.\n";
                            while(true)
                            {
                                cin >> coordX >> coordY;
                                // See if input fails
                                if(cin.fail())
                                {
                                    break;
                                }
                                tempArray[coordX][coordY] = CELL_ALIVE;
                                cout << "Spawned cell at (" << coordX << ", " << coordY << ")\n";
                            };
                            loop = false;
                        }
                        break;
                }
                Sleep(1000);
            }
        }
        option = tolower(getch());
    }while(option != 'q');

    return 0;
}

void loadFromFile(string filename, char array[MAX_ROW][MAX_COL], bool randomize)
{
    ifstream file;
    int startX = 0;
    int startY = 0;
    int coordX;
    char delimiter;
    int coordY;
    file.open((filename + ".txt").c_str());
    if(file.fail())
    {
        cout << "An error was encountered while attempting to load from the file.\n";
        return;
    }
    // Generate random spawnpoint for the pattern
    if(randomize)
    {
        startX = rand() % (MAX_ROW - 3);
        startY = rand() % (MAX_COL - 3);
    }
    while(!file.eof())
    {
        file >> coordX >> delimiter >> coordY;
        array[startX + coordX][startY + coordY] = CELL_ALIVE;
    }
    file.close();
    cout << "Successfully loaded!\n";
}

void saveToFile(string filename, const char array[MAX_ROW][MAX_COL])
{
    ofstream file;
    file.open((filename + ".txt").c_str());
    if(file.fail())
    {
        cout << "An error was encountered while saving.\n";
        return;
    }
    for(int coordX = 0; coordX < MAX_ROW; coordX++)
    {
        for(int coordY = 0; coordY < MAX_COL; coordY++)
        {
            if(array[coordX][coordY] == CELL_ALIVE)
            {
                file << coordX << "," << coordY << "\n";
            }
        }
    }
    file.close();
    cout << "Successfully saved!\n";
}

void displayMenu()
{
    cout <<
        left <<
        string(50, '=') << "\n\n" <<
        "[I] - Load 'U' pattern\n" <<
        "[1] - Load boat pattern (pattern1.txt)\n" <<
        "[2] - Load snake pattern (pattern2.txt)\n" <<
        "[3] - Load barge pattern (pattern3.txt)\n" <<
        "[T] - Create your own game. Syntax: <row>,<col>\n" <<
        "[P] - Start the reproduction cycle\n" <<
        "[S] - Stop the reproduction cycle\n" <<
        "[C] - Wipe out all living cells\n" <<
        "[L] - Loads game from a saved file\n" <<
        "[A] - Save current game to a file\n" <<
        "[Q] - Exit the game\n\n" <<
        string(50, '=') << "\n\n";
}

void displayArray(const char array[MAX_ROW][MAX_COL])
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

void copyArray(const char fromArray[MAX_ROW][MAX_COL], char toArray[MAX_ROW][MAX_COL])
{
    for(int coordX = 0; coordX < MAX_ROW; coordX++)
    {
        for(int coordY = 0; coordY < MAX_COL; coordY++)
        {
            toArray[coordX][coordY] = fromArray[coordX][coordY];
        }
    }
}

void setZeroArray(char array[MAX_ROW][MAX_COL])
{
    for(int coordX = 0; coordX < MAX_ROW; coordX++)
    {
        for(int coordY = 0; coordY < MAX_COL; coordY++)
        {
            array[coordX][coordY] = CELL_DEAD;
        }
    }
}

void setInitialPatternArray(char array[MAX_ROW][MAX_COL])
{
    int startX = rand() % (MAX_ROW - PATTERN_HEIGHT);
    int startY = rand() % (MAX_COL - PATTERN_WIDTH);
    // Set the two vertical lines
    for(int len = 0; len < PATTERN_HEIGHT; len++)
    {
        array[startX + len][startY] = CELL_ALIVE;
        array[startX + len][startY + (PATTERN_WIDTH - 1)] = CELL_ALIVE; // For the second side of the pattern
    }
    // Set the horizontal line at the bottom
    for(int len = 0; len < PATTERN_WIDTH; len++)
    {
        array[startX + (PATTERN_HEIGHT - 1)][startY + len] = CELL_ALIVE;
    }
}

void setNextGenArray(const char fromArray[MAX_ROW][MAX_COL], char toArray[MAX_ROW][MAX_COL])
{
    for(int coordX = 0; coordX < MAX_ROW; coordX++)
    {
        for(int coordY = 0; coordY < MAX_COL; coordY++)
        {
            int alive = 0;
            // Top-left corner
            if((coordX == 0) && (coordY == 0))
            {
                if(fromArray[0][1] == CELL_ALIVE)
                    alive++;
                if(fromArray[1][1] == CELL_ALIVE)
                    alive++;
                if(fromArray[1][0] == CELL_ALIVE)
                    alive++;
            }
            // Top-right corner
            else if((coordX == 0) && (coordY == (MAX_COL - 1)))
            {
                if(fromArray[0][MAX_COL - 2] == CELL_ALIVE)
                    alive++;
                if(fromArray[1][MAX_COL - 2] == CELL_ALIVE)
                    alive++;
                if(fromArray[1][MAX_COL - 1] == CELL_ALIVE)
                    alive++;
            }
            // Bottom-left corner
            else if((coordX == (MAX_ROW - 1)) && (coordY == 0))
            {
                if(fromArray[MAX_ROW - 1][1] == CELL_ALIVE)
                    alive++;
                if(fromArray[MAX_ROW - 2][1] == CELL_ALIVE)
                    alive++;
                if(fromArray[MAX_ROW - 2][0] == CELL_ALIVE)
                    alive++;
            }
            // Bottom-right corner
            else if((coordX == (MAX_ROW - 1)) && (coordY == (MAX_COL - 1)))
            {
                if(fromArray[MAX_ROW - 1][MAX_COL - 2] == CELL_ALIVE)
                    alive++;
                if(fromArray[MAX_ROW - 2][MAX_COL - 2] == CELL_ALIVE)
                    alive++;
                if(fromArray[MAX_ROW - 2][MAX_COL - 1] == CELL_ALIVE)
                    alive++;
            }
            // Top edge
            else if(coordX == 0)
            {
                if(fromArray[0][coordY - 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[1][coordY - 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[1][coordY] == CELL_ALIVE)
                    alive++;
                if(fromArray[1][coordY + 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[0][coordY + 1] == CELL_ALIVE)
                    alive++;
            }
            // Bottom edge
            else if(coordX == (MAX_ROW - 1))
            {
                if(fromArray[MAX_ROW - 1][coordY - 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[MAX_ROW - 2][coordY - 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[MAX_ROW - 2][coordY] == CELL_ALIVE)
                    alive++;
                if(fromArray[MAX_ROW - 2][coordY + 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[MAX_ROW - 1][coordY + 1] == CELL_ALIVE)
                    alive++;
            }
            // Left edge
            else if(coordY == 0)
            {
                if(fromArray[coordX - 1][0] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX - 1][1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX][1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX + 1][1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX + 1][0] == CELL_ALIVE)
                    alive++;
            }
            // Right edge
            else if(coordY == (MAX_COL - 1))
            {
                if(fromArray[coordX - 1][MAX_COL - 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX - 1][MAX_COL - 2] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX][MAX_COL - 2] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX + 1][MAX_COL - 2] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX + 1][MAX_COL - 1] == CELL_ALIVE)
                    alive++;
            }
            // Away from all edges
            else
            {
                if(fromArray[coordX - 1][coordY - 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX - 1][coordY] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX - 1][coordY + 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX][coordY + 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX + 1][coordY + 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX + 1][coordY] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX + 1][coordY - 1] == CELL_ALIVE)
                    alive++;
                if(fromArray[coordX][coordY - 1] == CELL_ALIVE)
                    alive++;
            }
            // Check rules
            if(fromArray[coordX][coordY] == CELL_ALIVE)
            {
                if((alive == 2) || (alive == 3))
                {
                    toArray[coordX][coordY] = CELL_ALIVE;
                }
                // Died from overpopulation/underpopulation
                else
                {
                    toArray[coordX][coordY] = CELL_DEAD;
                }
            }
            else
            {
                // Born from reproduction
                if(alive == 3)
                {
                    toArray[coordX][coordY] = CELL_ALIVE;
                }
                else
                {
                    toArray[coordX][coordY] = CELL_DEAD;
                }
            }
        }
    }
}