#include <iostream>

using namespace std;

bool validateUserInput(int firstInput, int secondInput);
void oddNumbers(int minNum, int maxNum);
int sumEvenNumbers(int minNum, int maxNum);
void displaySquareNumbers(int minNum, int maxNum);
int sumSquareOddNumbers(int minNum, int maxNum);
void displayUppercaseLetters(char minLetter, char maxLetter);

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
            if(validateUserInput(firstNum, secondNum))
            {
                success = true;
                break;
            }
        }
        
        // b
        oddNumbers(firstNum, secondNum);
        
        // c
        int sumEven = sumEvenNumbers(firstNum, secondNum);
        cout << "Sum of even integers between " << firstNum << " and " << secondNum <<  " = " << sumEven << "\n\n";
        
        // d
        displaySquareNumbers(1, 10);
        
        // e
        int sumSquareOdd = sumSquareOddNumbers(firstNum, secondNum);
        cout << "Sum of the squares of odd integers between " << firstNum << " and " << secondNum << " = " << sumSquareOdd << "\n\n";
        
        // f
        displayUppercaseLetters('A', 'Z');
        
        // Ask if user wants to repeat program; if so, start again from the top
        cout <<
            "Do you want to repeat this program?\n"
            "y/n\n"
            "> ";
        cin >> repeat;
    }
    
    return 0;
}

bool validateUserInput(int firstInput, int secondInput)
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
        return false;
    }
    // Check for negatives
    else if((firstInput < 0) || (secondInput < 0))
    {
        cout <<
            "\n"
            "No negative numbers!\n"
            "Please try again.\n\n";
        return false;
    }
    // Check if firstInput is bigger than secondInput
    else if(firstInput > secondInput)
    {
        cout <<
            "\n"
            "First number must be less than the second number!\n"
            "Please try again.\n\n";
        return false;
    }
    else
    {
        cout << "\n";
        return true;
    }
}

void oddNumbers(int minNum, int maxNum)
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

int sumEvenNumbers(int minNum, int maxNum)
{
    int counter = minNum;
    int sum = 0;
    while(counter <= maxNum)
    {
        if((counter % 2) == 0)
        {
            sum += counter;
        }
        counter++;
    }
    return sum;
}

void displaySquareNumbers(int minNum, int maxNum)
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

int sumSquareOddNumbers(int minNum, int maxNum)
{
    int counter = minNum;
    int sum = 0;
    while(counter <= maxNum)
    {
        if((counter % 2) == 1)
        {
            sum += counter * counter;
        }
        counter++;
    }
    return sum;
}

void displayUppercaseLetters(char minLetter, char maxLetter)
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