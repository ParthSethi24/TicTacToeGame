#include <iostream>
using namespace std;

int main()
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int choice;
    int row, col;
    char player = 'X';
    bool gameover = false;
    char playagain;

    cout << "==============================" << endl;
    cout << "       TIC TAC TOE GAME       " << endl;
    cout << "==============================" << endl;

    do
    {
        gameover = false;
        player = 'X';

        while (!gameover)
        {
            cout << endl;

            // Display the game board
            cout << "       |       |       " << endl;
            cout << "   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << endl;
            cout << "_______|_______|_______" << endl;

            cout << "       |       |       " << endl;
            cout << "   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << endl;
            cout << "_______|_______|_______" << endl;

            cout << "       |       |       " << endl;
            cout << "   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << endl;
            cout << "       |       |       " << endl;

            cout << endl;
            cout << "Player " << player << ", enter your position (1-9): ";

            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a number! Try again." << endl;
                continue;
            }

            if (choice < 1 || choice > 9)
            {
                cout << "Invalid position! Try again." << endl;
                continue;
            }

            // Convert the position into row and column
            row = (choice - 1) / 3;
            col = (choice - 1) % 3;

            if (board[row][col] == 'X' || board[row][col] == 'O')
            {
                cout << "This position is already occupied!" << endl;
                continue;
            }

            board[row][col] = player;

            // Check rows and columns
            for (int i = 0; i < 3; i++)
            {
                if (board[i][0] == player &&
                    board[i][1] == player &&
                    board[i][2] == player)
                {
                    gameover = true;
                }

                if (board[0][i] == player &&
                    board[1][i] == player &&
                    board[2][i] == player)
                {
                    gameover = true;
                }
            }

            // Check diagonals
            if (board[0][0] == player &&
                board[1][1] == player &&
                board[2][2] == player)
            {
                gameover = true;
            }

            if (board[0][2] == player &&
                board[1][1] == player &&
                board[2][0] == player)
            {
                gameover = true;
            }

            if (gameover)
            {
                cout << endl;
                cout << "Player " << player << " wins!" << endl;
                break;
            }

            // Check whether the game is a draw
            bool draw = true;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] != 'X' && board[i][j] != 'O')
                    {
                        draw = false;
                    }
                }
            }

            if (draw)
            {
                cout << endl;
                cout << "Game Draw!" << endl;
                gameover = true;
                break;
            }

            // Change the player
            if (player == 'X')
            {
                player = 'O';
            }
            else
            {
                player = 'X';
            }
        }

        // Display the final board
        cout << endl;
        cout << "Final Board:" << endl;
        cout << "   " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "  ---|---|---" << endl;
        cout << "   " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "  ---|---|---" << endl;
        cout << "   " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

        cout << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playagain;

        if (playagain == 'y' || playagain == 'Y')
        {
            // Reset the board for a new game
            board[0][0] = '1';
            board[0][1] = '2';
            board[0][2] = '3';

            board[1][0] = '4';
            board[1][1] = '5';
            board[1][2] = '6';

            board[2][0] = '7';
            board[2][1] = '8';
            board[2][2] = '9';
        }

    } while (playagain == 'y' || playagain == 'Y');

    cout << endl;
    cout << "Thank you for playing!" << endl;

    return 0;
}
