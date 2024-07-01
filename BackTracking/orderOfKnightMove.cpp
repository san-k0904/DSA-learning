#include<iostream>
#include<vector>
using namespace std;
void PrintSolution(vector<vector<int>>sol){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<sol[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
bool IsSafe(vector<vector<int>>& sol,int row,int col){
    if(row>=0 && row<8 && col>=0 && col<8 && sol[row][col]==-1){
        return true;
    }
    return false;
}
bool KnightOrder(int row,int col,vector<vector<int>>& sol,int move_num,int Rowattacked[],int Colattacked[]){
    int n=sol.size();
    if(move_num ==n*n){
        return true;
    }
    for(int i=0;i<8;i++){
        int newCol= col+Colattacked[i];
        int newRow= row+Rowattacked[i];
        if(IsSafe(sol,newRow,newCol)){
            sol[newRow][newCol]=move_num;
            if(KnightOrder(newRow,newCol,sol,move_num+1,Rowattacked,Colattacked)){
                return true;
            }
            else{
                sol[newRow][newCol]=-1;
            }
        }
    }
    return false;
}

int main(){
    int N=8;
    vector<vector <int>>sol(8,vector<int>(8,-1));
    int Rowattacked[]={-2,-2,-1,-1,1,1,2,2};
    int Colattacked[]={-1,1,-2,2,-2,2,-1,1};
    sol[0][0]=0;
    if(KnightOrder(0,0,sol,1,Rowattacked,Colattacked)){
        PrintSolution(sol);
    }
    else{
        cout<<"No order possible.\n";
    }
    return 0;

}