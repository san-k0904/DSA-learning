#include<iostream>
#include<vector>
using namespace std;
int firstOccur(vector<int>& arr,int target,int i){
    if(i==arr.size()){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return firstOccur(arr,target,i+1);
}
int LastOccur(vector<int>& arr,int target,int i){
    if(i<0){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return LastOccur(arr,target,i-1);
}
int main(){
    vector<int> arr={0,1,2,3,3,2,4};
    int target=2;
    cout<< firstOccur(arr,target,0)<<"\n";
    cout<< LastOccur(arr,target,arr.size()-1)<<"\n";
    return 0;
}