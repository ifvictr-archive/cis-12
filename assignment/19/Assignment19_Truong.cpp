#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int ranges[8][2] = {
        // {min, max}
        {0, 24},
        {25, 49},
        {50, 74},
        {75, 99},
        {100, 124},
        {125, 149},
        {150, 174},
        {175, 200}
    };
    int rangeCounts[8] = {};
    int score;
    ifstream file;
    
    file.open("Data.txt");
    if(file.fail())
    {
        cout << "Failed to open file.\n";
        return 1;
    }
    while(!file.eof())
    {
        file >> score;
        for(int i = 0; i < 8; i++)
        {
            if((score >= ranges[i][0]) && (score <= ranges[i][1]))
            {
                rangeCounts[i]++;
                break;
            }
        }
    }
    
    cout << setw(8) << "Range" << setw(21) << "# of Students\n";
    for(int i = 0; i < 8; i++)
    {
        cout << setw(3) << ranges[i][0] << " - " << setw(3) << ranges[i][1] << setw(15) << rangeCounts[i] << "\n";
    }
    
    return 0;
}