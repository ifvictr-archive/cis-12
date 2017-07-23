#include <iostream>
#include <string>

using namespace std;

bool validateUserInput(int year);
string returnRomanThousandsPlace(int year);
string returnRomanHundredsPlace(int year);
string returnRomanTensPlace(int year);
string returnRomanOnesPlace(int year);

int main()
{
    bool success = false;
    char repeat = 'y';
    int year = 0;
    
    while(repeat == 'y')
    {
        success = false; // Resets success so it doesn't just auto-output the previous results (only applies if repeated)
        
        cout <<
            "This program will accept a year written in four digit ordinary numeral and will\n"
            "convert it into roman numerals.\n\n"
            "Enter a year between 1000 and 3000:\n";
        while(!success)
        {
            cin >> year;
            if(validateUserInput(year))
            {
                success = true;
                break;
            }
            else
            {
                cout << "\nThe year entered is invalid. Enter a valid year between 1000 to 3000:\n";
            }
        }
        
        cout << "\nYour number in roman numerals is: " << returnRomanThousandsPlace(year) << returnRomanHundredsPlace(year) << returnRomanTensPlace(year) << returnRomanOnesPlace(year) << "\n\n";
        cout << "Do you want to repeat the program again? y or n\n";
        cin >> repeat;
    }
    
    return 0;
}

bool validateUserInput(int year)
{
    if(!cin.fail() && (year >= 1000) && (year <= 3000))
    {
        return true;
    }
    else
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
}

string returnRomanThousandsPlace(int year)
{
    string r;
    if((year >= 1000) && (year <= 1999))
    {
        r = "M";
    }
    else if((year >= 2000) && (year <= 2999))
    {
        r = "MM";
    }
    else if(year >= 3000)
    {
        r = "MMM";
    }
    return r;
}

string returnRomanHundredsPlace(int year)
{
    string r;
    year %= 1000;
    if((year >= 100) && (year <= 199))
    {
        r = "C";
    }
    else if((year >= 200) && (year <= 299))
    {
        r = "CC";
    }
    else if((year >= 300) && (year <= 399))
    {
        r = "CCC";
    }
    else if((year >= 400) && (year <= 499))
    {
        r = "CD";
    }
    else if((year >= 500) && (year <= 599))
    {
        r = "D";
    }
    else if((year >= 600) && (year <= 699))
    {
        r = "DC";
    }
    else if((year >= 700) && (year <= 799))
    {
        r = "DCC";
    }
    else if((year >= 800) && (year <= 899))
    {
        r = "DCCC";
    }
    else if((year >= 900) && (year <= 999))
    {
        r = "CM";
    }
    return r;
}

string returnRomanTensPlace(int year)
{
    string r;
    year %= 100;
    if((year >= 10) && (year <= 19))
    {
        r = "X";
    }
    else if((year >= 20) && (year <= 29))
    {
        r = "XX";
    }
    else if((year >= 30) && (year <= 39))
    {
        r = "XXX";
    }
    else if((year >= 40) && (year <= 49))
    {
        r = "XL";
    }
    else if((year >= 50) && (year <= 59))
    {
        r = "L";
    }
    else if((year >= 60) && (year <= 69))
    {
        r = "LX";
    }
    else if((year >= 70) && (year <= 79))
    {
        r = "LXX";
    }
    else if((year >= 80) && (year <= 89))
    {
        r = "LXXX";
    }
    else if((year >= 90) && (year <= 99))
    {
        r = "XC";
    }
    return r;
}

string returnRomanOnesPlace(int year)
{
    switch(year % 10)
    {
        case 1:
            return "I";
        case 2:
            return "II";
        case 3:
            return "III";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 6:
            return "VI";
        case 7:
            return "VII";
        case 8:
            return "VIII";
        case 9:
            return "IX";
    }
}