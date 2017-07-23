#include <iomanip>
#include <iostream>

using namespace std;

bool validateUserInputTime(int hour, int minute);
bool validateUserInputDay(char letter1, char letter2);
bool validateUserInputCallLength(int minutes);
float calculateTotalCost(int hour, int minute, char day, int length);

int main()
{
    bool success = false;
    char repeat = 'y';

    int hour = 0;
    char colon; // Blah
    int minute = 0;

    char dayFirstLetter;
    char daySecondLetter;

    int length = 0;
    
    while(repeat == 'y')
    {
        // Get call start time
        success = false; // To reset when user repeats program
        while(!success)
        {
            cout << "Enter the time the call starts in 24-hour rotation:\n";
            cin >> hour >> colon >> minute;
            success = validateUserInputTime(hour, minute);
        }
        
        // Get day of week
        success = false;
        while(!success)
        {
            cout << "Enter the first two letters of the day of the week:\n";
            cin >> dayFirstLetter >> daySecondLetter;
            success = validateUserInputDay(dayFirstLetter, daySecondLetter);
        }
        
        // Get call length
        success = false;
        while(!success)
        {
            cout << "Enter the length of the call in minutes:\n";
            cin >> length;
            success = validateUserInputCallLength(length);
        }
        
        cout << setprecision(2) << fixed; // Show only two digits after decimal
        cout << "Cost of the call: $" << calculateTotalCost(hour, minute, dayFirstLetter, length) << "\n\n\n";
        cout << "Do you want to repeat the program?\n";
        cin >> repeat;
    }
    return 0;
}

bool validateUserInputTime(int hour, int minute)
{
    if(!cin.fail() && (hour >= 0) && (hour <= 23) && (minute >= 0) && (minute <= 59))
    {
        cout << "\n";
        return true;
    }
    else
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<
            "\n"
            "Invalid time input.\n"
            "Please try again.\n\n";
        return false;
    }
}

bool validateUserInputDay(char letter1, char letter2)
{
    letter1 = tolower(letter1);
    letter2 = tolower(letter2);
    // Validate day of the week
    if(
        (letter1 == 'm' && letter2 == 'o') || // Monday
        (letter1 == 't' && letter2 == 'u') || // Tuesday
        (letter1 == 'w' && letter2 == 'e') || // Wednesday
        (letter1 == 't' && letter2 == 'h') || // Thursday
        (letter1 == 'f' && letter2 == 'r') || // Friday
        (letter1 == 's' && letter2 == 'a') || // Saturday
        (letter1 == 's' && letter2 == 'u') // Sunday
    )
    {
        cout << "\n";
        return true;
    }
    else
    {
        cout <<
            "\n"
            "Invalid day input.\n"
            "Please try again.\n\n";
        return false;
    }
}

bool validateUserInputCallLength(int minutes)
{
    if(!cin.fail() && (minutes >= 0))
    {
        cout << "\n";
        return true;
    }
    else
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<
            "\n"
            "Invalid minute input.\n"
            "Please try again.\n\n";
        return false;
    }
}

float calculateTotalCost(int hour, int minute, char day, int length)
{
    float cost = 0;
    int time = (hour * 60) + minute; // Time of call in seconds
    switch(tolower(day))
    {
        // Monday-Friday
        case 'm':
        case 't':
        case 'w':
        case 'f':
            // $0.40/min when Monday-Friday and 8AM-6PM
            if((time >= (8 * 60)) && (time <= (18 * 60)))
            {
                cost = length * 0.40;
            }
            // $0.25/min when Monday-Friday and 6:01PM-7:59AM
            else if((time < (8 * 60)) || (time > (18 * 60)))
            {
                cost = length * 0.25;
            }
            break;
        // $0.15/min when Saturday or Sunday
        case 's':
            cost = length * 0.15;
            break;
    }
    return cost;
}