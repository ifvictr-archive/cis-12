#include <iostream>

using namespace std;

int main()
{
    // Get three numbers
    int x;
    int y;
    int z;
    // For putting in order later
    int r1;
    int r2;
    int r3;
    cout << "Please input three integers:\n";
    cout << ">> ";
    cin >> x >> y >> z;
    // Sort x, y, and z into ascending order
    // {y, x}
    if(x > y)
    {
        // {y, x?, z, x?}
        if(y < z)
        {
            // {y, x, z}
            if(x < z)
            {
                r1 = y;
                r2 = x;
                r3 = z;
            }
            // {y, z, x}, (x > z) || (x == z)
            else
            {
                r1 = y;
                r2 = z;
                r3 = x;
            }
        }
        // {z, y, x}, (y > z) || (y == z)
        else
        {
            r1 = z;
            r2 = y;
            r3 = x;
        }
    }
    // {x, y}, (x < y) || (x == y)
    else
    {
        // {z?, x, z?, y}
        if(y > z)
        {
            // {z, x, y}
            if(x > z)
            {
                r1 = z;
                r2 = x;
                r3 = y;
            }
            // {x, z, y}, (x < z) || (x == z)
            else
            {
                r1 = x;
                r2 = z;
                r3 = y;
            }
        }
        // {x, y, z}, (y < z) || (y == z)
        else
        {
            r1 = x;
            r2 = y;
            r3 = z;
        }
    }
    // Output results
    cout << "Input three integer numbers in ascending order:\n";
    cout << r1 << " " << r2 << " " << r3;
    // Return with no errors
    return 0;
}