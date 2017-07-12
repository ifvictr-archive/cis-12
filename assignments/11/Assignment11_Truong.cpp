#include <iostream>

using namespace std;

int main()
{
    bool success = false;
    int firstNum = 0;
    int secondNum = 0;
    int sum = 0;
    
    // a
    cout << 
        "Enter two positive integer numbers.\n"
        "First number must be less than the second number:\n"
        "Enter numbers: ";
    for(;;)
    {
        if(success){
            break;
        }
        cin >> firstNum >> secondNum;
        // Check if firstNum is bigger than secondNum
        if(firstNum > secondNum)
        {
            cout <<
                "\n"
                "First number must be less than the second number!\n"
                "Please try again.\n";
        }
        // Check for negatives
        else if((firstNum < 0) || (secondNum < 0))
        {
            cout <<
                "\n"
                "No negative numbers!\n"
                "Please try again.\n";
        }
        else
        {
            success = true;
        }
    }
    cout << "\n";
    
    // b
    cout << "Odd integers between " << firstNum << " and " << secondNum << " are:\n";
    for(int i = firstNum; i <= secondNum; i++)
    {
        if((i % 2) == 1)
        {
            cout << i << " ";
        }
    }
    cout << "\n\n";
    
    // c
    for(int i = firstNum; i <= secondNum; i++)
    {
        if((i % 2) == 0)
        {
            sum += i;
        }
    }
    cout << "Sum of even integers between " << firstNum << " and " << secondNum << " = " << sum << "\n\n";
    
    // d
    cout << "Number Square of Number\n";
    for(int i = 1; i <= 10; i++)
    {
        cout << i << "\t" << (i * i) << "\n";
    }
    cout << "\n";
    
    // e
    sum = 0; // Reset sum
    for(int i = firstNum; i <= secondNum; i++)
    {
        if((i % 2) == 1)
        {
            sum += i * i;
        }
    }
    cout << "Sum of the squares of odd integers between " << firstNum << " and " << secondNum << " = " << sum << "\n\n";
    
    // f
    cout << "Upper case letters are: ";
    for(int i = 65; i <= 90; i++) // 65 is ASCII decimal code for 'A', 90 is for 'Z'
    {
        cout << static_cast<char>(i) << " "; // Get ASCII character from decimal code
    }
    
    return 0;
}