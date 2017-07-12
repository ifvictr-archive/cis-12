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
    cout << 
        "Enter two positive integer numbers.\n"
        "First number must be less than the second number:\n"
        "Enter numbers: ";
    do
    {
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
    }while(!success);
    cout << "\n";
    
    // b
    counter = firstNum; // Set counter
    cout << "Odd integers between " << firstNum << " and " << secondNum << " are:\n";
    do
    {
        if((counter % 2) == 1)
        {
            cout << counter << " ";
        }
        counter++;
    }while(counter <= secondNum);
    cout << "\n\n";
    
    // c
    counter = firstNum; // Reset counter
    do
    {
        if((counter % 2) == 0)
        {
            sum += counter;
        }
        counter++;
    }while(counter <= secondNum);
    cout << "Sum of even integers between " << firstNum << " and " << secondNum << " = " << sum << "\n\n";
    
    // d
    counter = 1; // Reset counter
    cout << "Number Square of Number\n";
    do
    {
        cout << counter << "\t" << (counter * counter) << "\n";
        counter++;
    }while(counter <= 10);
    cout << "\n";
    
    // e
    counter = firstNum; // Reset counter
    sum = 0; // Reset sum
    do
    {
        if((counter % 2) == 1)
        {
            sum += counter * counter;
        }
        counter++;
    }while(counter <= secondNum);
    cout << "Sum of the squares of odd integers between " << firstNum << " and " << secondNum << " = " << sum << "\n\n";
    
    // f
    counter = 65; // 65 is ASCII decimal code for 'A'
    cout << "Upper case letters are: ";
    do
    {
        cout << static_cast<char>(counter) << " "; // Get ASCII character from decimal code
        counter++;
    }while(counter <= 90); // 90 is ASCII decimal code for 'Z'
    
    return 0;
}