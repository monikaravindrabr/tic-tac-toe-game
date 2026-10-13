#include <iostream>
using namespace std;

// Display the game board
void displayBoard(char board[])
{
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

// Check whether a player has won
bool checkWinner(char board[], char player)
{
    // Winning rows
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == player &&
            board[i + 1] == player &&
            board[i + 2] == player)
        {
            return true;
        }
    }

    // Winning columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == player &&
            board[i + 3] == player &&
            board[i + 6] == player)
        {
            return true;
        }
    }

    // Diagonals
    if (board[0] == player &&
        board[4] == player &&
        board[8] == player)
    {
        return true;
    }

    if (board[2] == player &&
        board[4] == player &&
        board[6] == player)
    {
        return true;
    }

    return false;
}

// Main game
int main()
{
    char board[9] = {'1', '2', '3',
                     '4', '5', '6',
                     '7', '8', '9'};

    char currentPlayer = 'X';
    int position;
    int moves = 0;
    char playAgain;

    cout << "========================\n";
    cout << "    TIC-TAC-TOE GAME\n";
    cout << "========================\n";

    do
    {
        // Reset the board for each game
        for (int i = 0; i < 9; i++)
        {
            board[i] = '1' + i;
        }

        currentPlayer = 'X';
        moves = 0;

        while (true)
        {
            displayBoard(board);

            cout << "Player " << currentPlayer;
            cout << ", choose a position (1-9): ";

            if (!(cin >> position))
            {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            // Validate the position
            if (position < 1 || position > 9)
            {
                cout << "Invalid position! Choose between 1 and 9.\n";
                continue;
            }

            // Check whether the position is occupied
            if (board[position - 1] == 'X' ||
                board[position - 1] == 'O')
            {
                cout << "That position is already occupied!\n";
                continue;
            }

            // Place the player's symbol
            board[position - 1] = currentPlayer;
            moves++;

            // Check for a winner
            if (checkWinner(board, currentPlayer))
            {
                displayBoard(board);
                cout << "Congratulations! Player "
                     << currentPlayer << " wins!\n";
                break;
            }

            // Check for a draw
            if (moves == 9)
            {
                displayBoard(board);
                cout << "It's a draw!\n";
                break;
            }

            // Switch players
            if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer = 'X';
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing Tic-Tac-Toe!\n";

    return 0;
}