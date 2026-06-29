#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard()
{
    char num = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = num++;
        }
    }
}

void displayBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool placeMark(int choice)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin()
{

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

int main()
{

    char playAgain;

    do
    {

        initializeBoard();
        currentPlayer = 'X';

        while (true)
        {

            displayBoard();

            int choice;

            cout << "Player " << currentPlayer << ", Enter position (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9 || !placeMark(choice))
            {
                cout << "Invalid Move! Try Again.\n";
                continue;
            }

            if (checkWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " Wins!\n";
                break;
            }

            if (checkDraw())
            {
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Play Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing!\n";

    return 0;
}