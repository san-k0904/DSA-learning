#include<iostream>
using namespace std;
void Print_SpiralMatrix(int arr[][4],int n,int m){
    int scol=0, ecol=m-1;
    int srow=0, erow=n-1;
    while(scol<=ecol && srow<=erow){
        //top
        for(int j=scol;j<=ecol;j++){
            cout<<arr[srow][j]<<" ";
        }
        //right
        for(int i=srow+1;i<=erow;i++){
            cout<<arr[i][ecol]<<" ";
        }
        //bottom
        for(int j=ecol-1;j>=scol;j--){
            if(srow==erow){//in case odd number rows
                break;
            }
            cout<<arr[erow][j]<<" ";
        }
        for(int i=erow-1;i>=srow+1;i--){
            if(scol==ecol){//in case of odd number cols
                break;
            }
            cout<<arr[i][scol]<<" ";
        }
        scol++; ecol--;
        srow++; erow--;
    } 
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    int arr[n][4];//CAN'T take m coz in function we assigned a static value for m in int arr[][4]..i.e 4 so m HAS TO BE 4 ONLY
    cout<<"Enter Numbers: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    Print_SpiralMatrix(arr,n,4);
    return 0;
}