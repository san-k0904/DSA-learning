#include<iostream>
using namespace std;
bool Duplicate(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
                return true;
        }
    }
    return false;
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
    cout<<(boolalpha)<<Duplicate(arr,n)<<endl;
    return 0;

}