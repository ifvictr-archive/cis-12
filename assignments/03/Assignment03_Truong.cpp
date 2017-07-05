#include <iostream>

using namespace std;

int main()
{
    // Get integer input
    int n;
    cout << "Please enter an integer number.\n";
    cout << ">> ";
    cin >> n;
    // n is zero or positive
    if(n >= 0)
    {
        // n is zero
        if(n == 0)
        {
            cout << "You entered zero.";
        }
        // n is positive
        else
        {
            cout << "You entered a positive number.";
        }
    }
    // n is negative
    else
    {
        cout << "You entered a negative number.";
    }
    // Return with no errors
    return 0;
}