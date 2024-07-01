#include<iostream>
using namespace std;
#include<cstring>
void array1D_2D(int arr[],int mat[][3],int m,int size1D,int n=3){//rows=m cols=n also default value should always be at the end
    int k=0, row=0;
    if(m*n<size1D)
        return;
    else{
        while(k<size1D){
            for(int i=0;i<=n-1;i++){
                if(k==size1D)
                    break;
                mat[row][i]=arr[k++];
                
            }
            row++;  
        }
        
    }
}
int main(){
    int m;
    cout<<"Enter no. of row: ";//didn't ask col coz in c++ if using 2D array while passing in function we have to give a static value manually
    cin>>m;
    int arr[]={1,2,3,4,5,6,7};
    int size1D=sizeof(arr)/sizeof(int);
    int mat[m][3];
    memset(mat,0,sizeof(mat));
    array1D_2D(arr,mat,m,size1D);
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
    
}