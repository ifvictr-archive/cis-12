#include <iostream>

using namespace std;

int main()
{
    // Get door dimensions
    int doorLength;
    int doorWidth;
    cout << "Enter the length and width of the door: ";
    cin >> doorLength >> doorWidth;
    // Get first window dimensions
    int window1Length;
    int window1Width;
    cout << "Enter the length and width of the first window: ";
    cin >> window1Length >> window1Width;
    // Get second window dimensions
    int window2Length;
    int window2Width;
    cout << "Enter the length and width of second window: ";
    cin >> window2Length >> window2Width;
    // Get bookshelf dimensions
    int shelfLength;
    int shelfWidth;
    cout << "Enter the length and width of the bookshelf: ";
    cin >> shelfLength >> shelfWidth;
    // Get room dimensions
    int roomLength;
    int roomWidth;
    int roomHeight;
    cout << "Enter the length, width, and height of the room: ";
    cin >> roomLength >> roomWidth >> roomHeight;
    // Calculate amount of paint needed
    int wallArea = (roomLength * roomHeight + roomWidth * roomHeight) * 2;
    wallArea -= doorLength * doorWidth;
    wallArea -= window1Length * window1Width;
    wallArea -= window2Length * window2Width;
    wallArea -= shelfLength * shelfWidth;
    // Output results
    cout << "The amount of paint needed to paint the room: " << (wallArea / 120.0) << " gallons."; // 1 gallon of paint = 120 square feet
    // Return with no errors
    return 0;
}