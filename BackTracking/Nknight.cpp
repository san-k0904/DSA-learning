#include<iostream>
#include<vector>
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
bool isSafe(vector<vector<char>>& board,int row,int col,int n){
    int Rowattacked[]={-2,-2,-1,-1,1,1,2,2};
    int Colattacked[]={-1,1,-2,2,-2,2,-1,1};//order is based on where row is attacked
    for(int i=0;i<8;i++){
        int newRow= row+Rowattacked[i];
        int newCol= col+Colattacked[i];
        if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && board[newRow][newCol]=='K'){
            return false;
        }
    }
    return true;
}
int KnightsOnBoard(vector<vector<char>>& board,int row,int col,int no_of_knights){
    int n=board.size();
    if(no_of_knights==0){
        PrintBoard(board);
        return 1;
    }
    else if(row==n){
        return 0;
    }
    int count=0;
    for(int i=col;i<n;i++){
        if(isSafe(board,row,i,n)){
            board[row][i]='K';
            count+=KnightsOnBoard(board, row, i + 1, no_of_knights - 1);
            board[row][i] = '.'; 
        }
    }
    count+=KnightsOnBoard(board, row + 1, 0, no_of_knights);
    //coz as soon as all the columns traversed it won't enter the for loop
    //so backtrack won't occur only till the basecases hit.
    return count;
        
}
int main(){
    vector<vector<char>> board;
    int n=3;
    for(int i=0;i<n;i++){
        vector<char> newRow;
        for(int j=0;j<n;j++){//OR vector<char>newRow(n,'.');
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int count=KnightsOnBoard(board,0,0,n);
    cout<<"Total number of possible solutions: "<<count<<"\n";
    return 0;
}