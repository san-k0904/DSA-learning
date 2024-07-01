#include<iostream>
#include<vector>
#include<string>
using namespace std;
void SolveMazeChecker(vector<vector<int>>& maze,int row,int col,int n,string sol,vector<vector<bool>>& visited){
    if(row==n-1 && col==n-1 && maze[row][col]==1){
        cout<<sol<<"\n";
        return;
    }
    //up
    if(row-1>=0 && !visited[row][col] && maze[row][col]==1){
        visited[row][col]=true;
        SolveMazeChecker(maze,row-1,col,n,sol+"U",visited);
        visited[row][col]=false;
    }
    //down
    if(row+1<=n-1 && !visited[row][col] && maze[row][col]==1){
        visited[row][col]=true;
        SolveMazeChecker(maze,row+1,col,n,sol+"D",visited);
        visited[row][col]=false;
    }
    //left
    if(col-1>=0 && !visited[row][col] && maze[row][col]==1){
        visited[row][col]=true;
        SolveMazeChecker(maze,row,col-1,n,sol+"L",visited);
        visited[row][col]=false;
    }
    //right
    if(col+1<=n-1 && !visited[row][col] && maze[row][col]==1){
        visited[row][col]=true;
        SolveMazeChecker(maze,row,col+1,n,sol+"R",visited);
        visited[row][col]=false;
    }


}
void solveMaze(vector<vector<int>>maze,int n){
    string sol="";
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    if(maze[0][0]==1){
        SolveMazeChecker(maze,0,0,n,sol,visited);
    }

}
int main(){
    vector<vector<int>>maze={
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    int n=4;
    // cout<<"Enter value for n: ";
    // cin>>n;
    // cout<<"Enter values: \n";
    // for(int i=0;i<n;i++){
    //     vector<int>newRow;
    //     for(int j=0;j<n;j++){
    //         char temp;
    //         cin>>temp;
    //         newRow.push_back(temp);
    //     }
    //     maze.push_back(newRow);
    //}
    solveMaze(maze,n);
    return 0;
}