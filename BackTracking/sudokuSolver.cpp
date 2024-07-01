#include<iostream>
#include<vector>
using namespace std;
void Printsudoku(vector<vector<int>> sudoku){

    for(int i=0;i<sudoku.size();i++){
        for(int j=0;j<sudoku.size();j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"-------------------------------\n";
}
bool isSafe(vector<vector<int>> sudoku,int row,int col,int digit){
    //horizontal check
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==digit){
            return false;
        }
    }
    //vertical check
    for(int i=0;i<9;i++){
        if(sudoku[i][col]==digit){
            return false;
        }
    }
    //grid check
    int StartRow= (row/3)*3;
    int StartCol= (col/3)*3;
    for(int i=StartRow;i<=StartRow+2;i++){
        for(int j=StartCol;j<=StartCol+2;j++){
            if(sudoku[i][j]==digit){
                return false;
            }
        }
    }
    return true;
}
bool SudokuSolver(vector<vector<int>> sudoku,int row,int col){
    if(row==9){
        //sudoku solved
        Printsudoku(sudoku);
        return true;
    }
    int nextRow=row;
    int nextCol=col+1;
    if(col+1==9){
        nextRow=row+1;
        nextCol=0;
    }
    if(sudoku[row][col]!=0){//means there is already a number there
        return SudokuSolver(sudoku,nextRow,nextCol);
    }
    for(int digit=1;digit<=9;digit++){
        if(isSafe(sudoku,row,col,digit)){
            sudoku[row][col]=digit;
            if(SudokuSolver(sudoku,nextRow,nextCol)){//means if the fn call that occured next is true then this call will also be true
            //i.e. only when sudoku is completely solved will we get a true value and then all the calls before it will also return true.
                return true;
            }
            sudoku[row][col]=0;//backtrack
        }
    }
    return false;
}
int main(){
    vector<vector<int>> sudoku = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    SudokuSolver(sudoku,0,0);
    return 0;
}