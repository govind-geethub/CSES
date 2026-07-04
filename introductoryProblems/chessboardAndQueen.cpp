#include<bits/stdc++.h>
using namespace std;

int ans = 0;
bool isSafe(int row, int col, vector<string> &board)
{
    // will only check the left as we are going left placed to right
    int dupRow = row;
    int dupCol = col;

    // diagonal check upper
    while(row >= 0 && col >= 0)
    {
        if(board[row][col] == 'q') return false;
        row--; col--;
    }

    //reset row col
    row = dupRow; col = dupCol;
    
    // diagonal check lower
    while(row < 8 &&col >= 0)
    {
        if(board[row][col] == 'q') return false;
        row++; col--;
    }

    // reset
    row = dupRow, col = dupCol;

    // left row
    while(col >= 0)
    {
        if(board[row][col] == 'q') return false;
        col--;
    }

    return true;
}

void chessAndQueen(int col, vector<string> &board)
{
    if(col == 8)
    {
        ans++;
        return;
    }

    for(int row=0; row<8; row++)
    {
        if(isSafe(row,col,board) && board[row][col] != '*') 
        {
            board[row][col] = 'q';
            chessAndQueen(col+1,board); // check next
            board[row][col] = '.';      // backtrack
        }
    }
}

int main()
{
    vector<string> board(8);
    for(int i=0; i<8; i++) cin >> board[i];

    chessAndQueen(0,board);
    cout << ans << endl;
    return 0;
}