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
    // Messages
    const string ROCK_WIN = "Rock breaks scissors.";
    const string PAPER_WIN = "Paper covers rock.";
    const string SCISSORS_WIN = "Scissors cut paper.";
    // Check who won
    switch(p1)
    {
        // Player 1 is rock
        case 'R':
        case 'r':
            switch(p2)
            {
                // rock < paper
                case 'P':
                case 'p':
                    cout << PAPER_WIN;
                    winner = 2;
                    break;
                // rock > scissors
                case 'S':
                case 's':
                    cout << ROCK_WIN;
                    winner = 1;
                    break;
            }
            break;
        // Player 1 is paper
        case 'P':
        case 'p':
            switch(p2)
            {
                // paper > rock
                case 'R':
                case 'r':
                    cout << PAPER_WIN;
                    winner = 1;
                    break;
                // paper < scissors
                case 'S':
                case 's':
                    cout << SCISSORS_WIN;
                    winner = 2;
                    break;
            }
            break;
        // Player 1 is scissors
        case 'S':
        case 's':
            switch(p2)
            {
                // scissors < rock
                case 'R':
                case 'r':
                    cout << ROCK_WIN;
                    winner = 2;
                    break;
                // scissors > paper
                case 'P':
                case 'p':
                    cout << SCISSORS_WIN;
                    winner = 1;
                    break;
            }
            break;
    }
    // Output winner
    switch(winner)
    {
        // Player 1 or 2 won
        case 1:
        case 2:
            cout << "\nPlayer " << winner << " WINS!";
            break;
        // There was a tie
        default:
            cout << "Nobody wins.";
            break;
    }
    // Return with no errors
    return 0;
}