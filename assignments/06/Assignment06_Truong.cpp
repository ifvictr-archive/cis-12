#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter an Integer Between 0 and 35: ";
    cin >> n;
    
    if((n >= 0) && (n <= 35))
    {
        if(n <= 9)
        {
            cout << n;
        }
        else
        {
            cout << static_cast<char>(n + 55); // In ASCII, 65 (10+55) = A, and 90 (35+55) = Z
        }
    }
    else
    {
        cout << "Invalid Input";
    }

    return 0;
}