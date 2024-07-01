#include<iostream>
using namespace std;
int maxProd_Subarray(int arr[],int n){
    int CurrmaxVal=arr[0];
    int CurrminVal=arr[0];//in order that if there are 2 -ves by say one at beginning and one the end of array then the min will suddenly become the maximum
    int curr;
    int result=CurrmaxVal;
    for(int i=1;i<n;i++){
        curr=arr[i];
        CurrminVal=min(curr,min(CurrmaxVal*curr,CurrminVal*curr));
        CurrmaxVal=max(curr,max(CurrmaxVal*curr,CurrminVal*curr));
        result=max(result,CurrmaxVal);

    }
    return result;
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
    cout<<maxProd_Subarray(arr,n)<<endl;
    return 0;
}