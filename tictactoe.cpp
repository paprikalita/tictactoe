#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

bool isWinner(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {

    cout<<"\n\n     TICK TAC TOE GAME"<<endl;
    cout<<"\tPlayer1 [X] \n\tPlayer2 [O]\n\n";

    cout<<"\t\t       |         |       \n";
    cout<<"\t\t  11   |  12     |  13   \n";
    cout<<"\t\t_______|_________|_____  \n";
    cout<<"\t\t       |         |       \n";
    cout<<"\t\t  21   |  22     |  23   \n";
    cout<<"\t\t_______|_________|_____  \n";
    cout<<"\t\t       |         |       \n";
    cout<<"\t\t  31   |  32     |  33   \n";
    cout<<"\t\t       |         |       \n\n";



    vector<vector<char>> board = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int currentPlayer = 1;
    int moveCount = 0;

    while (moveCount < 9) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column separated by a space): ";
        int row, col;
        cin >> row >> col;

        // Subtract 1 from row and col to match the 0-based indexing
        row--;
        col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move, please try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer == 1 ? 'X' : 'O';

        if (isWinner(board, currentPlayer == 1 ? 'X' : 'O')) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        currentPlayer = 3 - currentPlayer;
        moveCount++;
    }

    printBoard(board);

    if (moveCount == 9) {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
