#include <iostream>

using namespace std;

int main()
{
    // Get player choices
    char p1;
    char p2;
    int winner = 0;
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
    const string ROCK_WIN = "Rock breaks scissors.";
    const string PAPER_WIN = "Paper covers rock.";
    const string SCISSORS_WIN = "Scissors cut paper.";
    // Check who won
    // Player 1 is rock
    if(p1Rock)
    {
        // rock < paper
        if(p2Paper)
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
    // Player 1 is paper
    else if(p1Paper)
    {
        // paper > rock
        if(p2Rock)
        {
            cout << PAPER_WIN;
            winner = 1;
        }
        // paper < scissors
        else if(p2Scissors)
        {
            cout << SCISSORS_WIN;
            winner = 2;
        }
    }
    // Player 1 is scissors
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
    }
    // Output winner
    // Player 1 or 2 won
    if(winner != 0)
    {
        cout << "\nPlayer " << winner << " WINS!";
    }
    // There was a tie
    else
    {
        cout << "Nobody wins.";
    }
    // Return with no errors
    return 0;
}