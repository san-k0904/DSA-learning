#include<iostream>
using namespace std;

int MaxSubarraySum_BruteForce(int arr[],int n){//TIME COMPLEXITY O(n^3)
    int MaxSum=INT_MIN;//predefined macro for c and C++
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            int currentSum=0;
            for(int i=start;i<=end;i++){
                currentSum+=arr[i];
            }
            MaxSum=max(MaxSum,currentSum);
        }
    }
    return MaxSum;
}
int MaxSubarraySum_BruteForce_Optimized(int arr[],int n){//TIME COMPLEXITY O(n^2)
    int MaxSum=INT_MIN;//predefined macro for c and C++
    for(int start=0;start<n;start++){
        int currentSum=0;
        for(int end=start;end<n;end++){
            currentSum+=arr[end];//using the current sum of already calculated previous subsets
            MaxSum=max(MaxSum,currentSum);
        }
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
    cout<<MaxSubarraySum_BruteForce(arr,n)<<endl;
    cout<<MaxSubarraySum_BruteForce_Optimized(arr,n)<<endl;
    return 0;
    //ITS BETTER TO USE KADANE'S ALGORITHM AS IT'S DP AND TIME COMPLEXITY IS ONLY O(n);
}