#include <cctype>
#include <iostream>

using namespace std;

bool isAlphabetical(char character);
bool isVowel(char character);

int main()
{
    char character;
    char repeat = 'y';

    do
    {
        cout << "Enter an alphabet character: ";
        cin >> character;
        // Check if the input is an alphabetical character, if not then prompt user again
        if(!isAlphabetical(character))
        {
            cout <<
                "Invalid input.\n"
                "Please try again.\n\n";
            continue;
        }
        cout << character << " is a vowel: " << isVowel(character) << "\n";
        
        cout <<
            "Do you want to repeat this program?\n"
            "y/n\n"
            "> ";
        cin >> repeat;
    }while(repeat == 'y');
    
    return 0;
}

bool isAlphabetical(char character)
{
    int code = tolower(character);
    return (code >= 97) && (code <= 122); // 97-122 is a-z in ASCII, and any alphabetical character will fall between that range
}

bool isVowel(char character)
{
    switch(tolower(character))
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}