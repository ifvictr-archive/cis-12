#include <iostream>

using namespace std;

int main()
{
    bool success = false;
    int counter = 0;
    int firstNum = 0;
    int secondNum = 0;
    int sum = 0;
    
    // a
    while(!success)
    {
        cout << 
            "Enter two positive integer numbers.\n"
            "First number must be less than the second number:\n"
            "Enter numbers: ";
        cin >> firstNum >> secondNum;
        // Check for negatives
        if((firstNum < 0) || (secondNum < 0))
        {
            cout <<
                "\n"
                "No negative numbers!\n"
                "Please try again.\n\n";
        }
        // Check if firstNum is bigger than secondNum
        else if(firstNum > secondNum)
        {
            cout <<
                "\n"
                "First number must be less than the second number!\n"
                "Please try again.\n\n";
        }
        else
        {
            cout << "\n";
            success = true;
        }
    }
    
    // b
    counter = firstNum; // Set counter
    cout << "Odd integers between " << firstNum << " and " << secondNum << " are:\n";
    while(counter <= secondNum)
    {
        if((counter % 2) == 1)
        {
            cout << counter << " ";
        }
        counter++;
    }
    cout << "\n\n";
    
    // c
    counter = firstNum; // Reset counter
    while(counter <= secondNum)
    {
        if((counter % 2) == 0)
        {
            sum += counter;
        }
        counter++;
    }
    cout << "Sum of even integers between " << firstNum << " and " << secondNum << " = " << sum << "\n\n";
    
    // d
    counter = 1; // Reset counter
    cout << "Number Square of Number\n";
    while(counter <= 10)
    {
        cout << counter << "\t" << (counter * counter) << "\n";
        counter++;
    }
    cout << "\n";
    
    // e
    counter = firstNum; // Reset counter
    sum = 0; // Reset sum
    while(counter <= secondNum)
    {
        if((counter % 2) == 1)
        {
            sum += counter * counter;
        }
        counter++;
    }
    cout << "Sum of the squares of odd integers between " << firstNum << " and " << secondNum << " = " << sum << "\n\n";
    
    // f
    counter = 65; // 65 is ASCII decimal code for 'A'
    cout << "Upper case letters are: ";
    while(counter <= 90) // 90 is ASCII decimal code for 'Z'
    {
        cout << static_cast<char>(counter) << " "; // Get ASCII character from decimal code
        counter++;
    }
    
    return 0;
}