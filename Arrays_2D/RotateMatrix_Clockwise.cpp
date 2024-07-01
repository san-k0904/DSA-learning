#include<iostream>
using namespace std;

void Rotate(int mat[][3],int n=3){
    int temp;
    for(int i=0;i<=n/2;i++){
        for(int j=i+1;j<n;j++){
            temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            temp=mat[i][n-j-1];
            mat[i][n-j-1]=mat[i][j];
            mat[i][j]=temp;
        }
    }
}
int main(){
    int mat[3][3]={{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    Rotate(mat);
    cout<<"Rotated array: \n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
}