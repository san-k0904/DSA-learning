#include<iostream>
#include<vector>
#include<string>
using namespace std;
void PrintBoard(vector<vector<char>> board){

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"-------------------------------\n";
}
bool isSafe(vector<vector<char>> board,int row,int col,int n){
    //horizontal safe
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q')
            return false;
    }
    //vertical safe
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){//only have to check for blocks above
            return false;
        }
    }
    //diagonal upper left
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){ //coz as we go up row dec and col dec
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //diagonal upper right
    for(int i=row,j=col;i>=0 && j<n;i--,j++){//coz as we go up row dec and col inc
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
    
}
bool QueensOnBoard(vector<vector<char>>& board, int row, int n) {
    if (row == n) {
        PrintBoard(board);
        return true; // solution found
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i, n)) {
            board[row][i] = 'Q';
            if (QueensOnBoard(board, row + 1, n)) {
                return true; // solution found, no need to continue
            }
            board[row][i] = '.'; 
        }
    }
    return false; // no solution found
}

int main() {
    vector<vector<char>> board;
    int n = 2;
    for (int i = 0; i < n; i++) {
        vector<char> newRow;
        for (int j = 0; j < n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    if (!QueensOnBoard(board, 0, n)) {
        cout << "No solution found" << endl;
    } 
    return 0;
}