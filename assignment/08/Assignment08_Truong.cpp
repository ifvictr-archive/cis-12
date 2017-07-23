#include <iostream>

using namespace std;

int main()
{
    char op;
    int x;
    int y;
    
    cout << "Enter two integer numbers with an arithmetic operator (ex. 3 + 4):\n";
    cin >> x >> op >> y;
    cout << "\n";
    
    switch(op)
    {
        case '+':
            cout << x << " " << op << " " << y << " = " << (x + y);
            break;
        case '-':
            cout << x << " " << op << " " << y << " = " << (x - y);
            break;
        case '*':
            cout << x << " " << op << " " << y << " = " << (x * y);
            break;
        case '/':
            // Check for division by zero
            if(y != 0)
            {
                cout << x << " " << op << " " << y << " = " << (x / y);
            }
            else
            {
                cout << "Can't divide by 0.";
            }
            break;
        default:
            cout << "Illegal Operation.";
            break;
    }
    
    return 0;
}