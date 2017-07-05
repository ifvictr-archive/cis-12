#include <iostream>

using namespace std;

int main()
{
    // Get player choices
    char p1;
    char p2;
    int winner;
    cout << "Enter [R]ock, [P]aper, or [S]cissor\n";
    cout << "Player 1: ";
    cin >> p1;
    cout << "Enter [R]ock, [P]aper, or [S]cissor\n";
    cout << "Player 2: ";
    cin >> p2;
    cout << "\n";
    // For use in conditionals
    bool p1Rock = (p1 == 'R') || (p1 == 'r');
    bool p1Paper = (p1 == 'P') || (p1 == 'p');
    bool p1Scissors = (p1 == 'S') || (p1 == 's');
    bool p2Rock = (p2 == 'R') || (p2 == 'r');
    bool p2Paper = (p2 == 'P') || (p2 == 'p');
    bool p2Scissors = (p2 == 'S') || (p2 == 's');
    // Messages
    const string ROCK_WIN = "Rock breaks scissors";
    const string PAPER_WIN = "Paper covers rock";
    const string SCISSORS_WIN = "Scissors cut paper";
    const string NO_WIN = "Nobody wins";
    // Check who won
    if(p1Rock)
    {
        // rock = rock
        if(p2Rock)
        {
            cout << NO_WIN;
            winner = 0;
        }
        // rock < paper
        else if(p2Paper)
        {
            cout << PAPER_WIN;
            winner = 2;
        }
        // rock > scissors
        else if(p2Scissors)
        {
            cout << ROCK_WIN;
            winner = 1;
        }
    }
    else if(p1Paper)
    {
        // paper > rock
        if(p2Rock)
        {
            cout << PAPER_WIN;
            winner = 1;
        }
        // paper = paper
        else if(p2Paper)
        {
            cout << NO_WIN;
            winner = 0;
        }
        // paper < scissors
        else if(p2Scissors)
        {
            cout << SCISSORS_WIN;
            winner = 2;
        }
    }
    else if(p1Scissors)
    {
        // scissors < rock
        if(p2Rock)
        {
            cout << ROCK_WIN;
            winner = 2;
        }
        // scissors > paper
        else if(p2Paper)
        {
            cout << SCISSORS_WIN;
            winner = 1;
        }
        // scissors = scissors
        else if(p2Scissors)
        {
            cout << NO_WIN;
            winner = 0;
        }
    }
    // Output winner
    if(winner > 0)
    {
        cout << "\nPlayer " << winner << " WINS!";
    }
    // Return with no errors
    return 0;
}