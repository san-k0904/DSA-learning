#include<iostream>
using namespace std;
bool Staircase_Search(int matrix[][4],int n,int m,int key){//only when matrix is sorted row wise and col wise
    int i=0,j=m-1;//top right
    while(i<=n-1 && j>=0){
        if(matrix[i][j]==key){
            cout<<"Key at ( "<<i<<","<<j<<")\n";
            return true;
        }
        else if(matrix[i][j]>key){
            j--;//go left if element > key
        }
        else{
            i++;//go down when element < key
        }
    }
    cout<<"Key not found.\n";
    return false;
}
int main(){
    int n,key;
    cout<<"Enter number of rows & key: ";
    cin>>n>>key;
    int arr[n][4];//CAN'T take m coz in function we assigned a static value for m in int arr[][4]..i.e 4 so m HAS TO BE 4 ONLY
    cout<<"Enter Numbers: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    cout<<(boolalpha)<<Staircase_Search(arr,n,4,key);
    return 0;
}