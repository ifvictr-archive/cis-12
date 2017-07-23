#include <iostream>

using namespace std;

void validateUserInput(int firstInput, int secondInput, bool &success);
void oddNumbers(int &minNum, int &maxNum);
void sumEvenNumbers(int minNum, int maxNum, int &sum);
void displaySquareNumbers(int &minNum, int &maxNum);
void sumSquareOddNumbers(int minNum, int maxNum, int &sum);
void displayUppercaseLetters(char &minLetter, char &maxLetter);

int main()
{
    bool success = false;
    char repeat = 'y';
    int firstNum = 0;
    int secondNum = 0;

    while(repeat == 'y')
    {
        success = false; // Resets success so it doesn't just auto-output the previous results (only applies if repeated)
        
        // a
        while(!success)
        {
            cout << 
                "Enter two positive integer numbers.\n"
                "First number must be less than the second number:\n"
                "Enter numbers: ";
            cin >> firstNum >> secondNum;
            validateUserInput(firstNum, secondNum, success);
        }
        
        // b
        oddNumbers(firstNum, secondNum);
        
        // c
        int sumEven = 0;
        sumEvenNumbers(firstNum, secondNum, sumEven);
        cout << "Sum of even integers between " << firstNum << " and " << secondNum <<  " = " << sumEven << "\n\n";
        
        // d
        int minNum = 1;
        int maxNum = 10;
        displaySquareNumbers(minNum, maxNum);
        
        // e
        int sumSquareOdd = 0;
        sumSquareOddNumbers(firstNum, secondNum, sumSquareOdd);
        cout << "Sum of the squares of odd integers between " << firstNum << " and " << secondNum << " = " << sumSquareOdd << "\n\n";
        
        // f
        char minLetter = 'A';
        char maxLetter = 'Z';
        displayUppercaseLetters(minLetter, maxLetter);
        
        // Ask if user wants to repeat program; if so, start again from the top
        cout <<
            "Do you want to repeat this program?\n"
            "y/n\n"
            "> ";
        cin >> repeat;
    }
    
    return 0;
}

void validateUserInput(int firstInput, int secondInput, bool &success)
{
    // Check if both are integers
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<
            "\n"
            "Incorrect Input.\n"
            "Please try again.\n\n";
        success = false;
    }
    // Check for negatives
    else if((firstInput < 0) || (secondInput < 0))
    {
        cout <<
            "\n"
            "No negative numbers!\n"
            "Please try again.\n\n";
        success = false;
    }
    // Check if firstInput is bigger than secondInput
    else if(firstInput > secondInput)
    {
        cout <<
            "\n"
            "First number must be less than the second number!\n"
            "Please try again.\n\n";
        success = false;
    }
    else
    {
        cout << "\n";
        success = true;
    }
}

void oddNumbers(int &minNum, int &maxNum)
{
    int counter = minNum;
    cout << "Odd integers between " << minNum << " and " << maxNum << " are:\n";
    while(counter <= maxNum)
    {
        if((counter % 2) == 1)
        {
            cout << counter << " ";
        }
        counter++;
    }
    cout << "\n\n";
}

void sumEvenNumbers(int minNum, int maxNum, int &sum)
{
    int counter = minNum;
    while(counter <= maxNum)
    {
        if((counter % 2) == 0)
        {
            sum += counter;
        }
        counter++;
    }
}

void displaySquareNumbers(int &minNum, int &maxNum)
{
    int counter = minNum;
    cout << "Number Square of Number\n";
    while(counter <= maxNum)
    {
        cout << counter << "\t" << (counter * counter) << "\n";
        counter++;
    }
    cout << "\n";
}

void sumSquareOddNumbers(int minNum, int maxNum, int &sum)
{
    int counter = minNum;
    while(counter <= maxNum)
    {
        if((counter % 2) == 1)
        {
            sum += counter * counter;
        }
        counter++;
    }
}

void displayUppercaseLetters(char &minLetter, char &maxLetter)
{
    int counter = minLetter; 
    cout << "Upper case letters are: ";
    while(counter <= maxLetter)
    {
        cout << static_cast<char>(counter) << " "; // Get ASCII character from decimal code
        counter++;
    }
    cout << "\n\n\n";
}