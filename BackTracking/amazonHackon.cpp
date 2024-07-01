#include<iostream>
#include<vector>
using namespace std;

void QuickestRoute(vector<vector<char>>& city, int r, int c, int destRow, int destCol, vector<int>& pathlengths,vector<vector<bool>>& visited, int count = 1) {
    int n = city.size();
    if (r == destRow && c == destCol && city[r][c]=='P') {
        pathlengths.push_back(count);
        return;
    }
    //up
    if(r-1>=0 && !visited[r-1][c] && city[r][c]=='.'){
        visited[r][c]=true;//current position as true
        QuickestRoute(city, r - 1, c, destRow, destCol, pathlengths,visited, count + 1);
        visited[r][c]=false;
    }
    //down
    if(r+1<=n-1 && !visited[r+1][c] && city[r][c]=='.'){
        visited[r][c]=true;
        QuickestRoute(city, r + 1, c, destRow, destCol, pathlengths,visited, count + 1);
        visited[r][c]=false;
    }
    //left
    if(c-1>=0 && !visited[r][c-1] && city[r][c]=='.'){
        visited[r][c]=true;
        QuickestRoute(city, r, c - 1, destRow, destCol, pathlengths,visited, count + 1);
        visited[r][c]=false;
    }
    //right
    if(c+1<=n-1 && !visited[r][c+1] && city[r][c]=='.'){
        visited[r][c]=true;
        QuickestRoute(city, r, c + 1, destRow, destCol, pathlengths,visited, count + 1);
        visited[r][c]=false;
    }
}
int main(){
    vector<vector<char>>city;
    int n;
    vector<int>pathlengths;
    cout<<"Enter value for n: ";
    cin>>n;
    cout<<"Enter values: \n";
    for(int i=0;i<n;i++){
        vector<char>newRow;
        for(int j=0;j<n;j++){
            char temp;
            cin>>temp;
            newRow.push_back(temp);
        }
        city.push_back(newRow);
    }
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    int row1=0,col1=0;
    int row2=0,col2=0;
    int no_P=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(city[i][j]=='P'){
                if(no_P==0){
                    row1=i;
                    col1=j;
                }
                else{
                    row2=i;
                    col2=j;
                }
            }
                
        }
        if(no_P==2)
                break;
    }
    QuickestRoute(city,row1,col1,row2,col2,pathlengths,visited);
    if(pathlengths.size()==0){
        cout<<-1<<endl;
        return 0;
    }
    else{
        int shortestPath=INT_MAX;
        for(int i=0;i<pathlengths.size();i++){
            shortestPath=min(shortestPath,pathlengths[i]);
        }
        
        cout<<"Shortest Path is: "<<shortestPath<<endl; 
    }
    

    
    return 0;
}
