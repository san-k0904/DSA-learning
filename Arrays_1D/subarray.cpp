#include<iostream>
using namespace std;

void PrintSubarray(int arr[],int n){
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            for(int i=start;i<=end;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\t";
        }
        cout<<"\n";
    }
}
void inputArray(int arr[],int n){
    cout<<"Enter values: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void PrintArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    //n=sizeof(arr)/sizeof(int); //and it has to be in main only and not in any other function where the array is not created.
    inputArray(arr,n);
    PrintSubarray(arr,n);
    return 0;
}