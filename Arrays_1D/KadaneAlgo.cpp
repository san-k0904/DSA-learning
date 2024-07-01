#include<iostream>
using namespace std;

int KadaneAlgo_MaxSubarraySum(int arr[],int n){
    int MaxSum=INT_MIN;
    int currentSum=0;
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        MaxSum=max(MaxSum,currentSum);
        if(currentSum<0)
            currentSum=0;
    }
    return MaxSum;
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
    cout<<KadaneAlgo_MaxSubarraySum(arr,n)<<endl;
    return 0;
    //ITS BETTER TO USE KANE'S ALGORITHM AS IT'S DP AND TIME COMPLEXITY IS ONLY O(n);
}