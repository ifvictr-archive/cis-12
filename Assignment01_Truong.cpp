#include <iostream>

using namespace std;

int main(){
    // Display prompt
    cout << "Enter the elapsed time in seconds:\n";
    // Capture input
    int input;
    cin >> input;
    // Calculate values
    int hours = input / (60 * 60);
    int minutes = (input / 60) - (hours * 60);
    int seconds = input % 60;
    // Output results
    cout << "The elapsed time in seconds = " << input << "\n";
    cout << "The equivalent time in hours:minutes:seconds = " << hours << ":" << minutes << ":" << seconds << "\n";
    // Return with no errors
    return 0;
}