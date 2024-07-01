#include<iostream>
#include<vector>
using namespace std;
int Binary_Search_rec(vector<int>& arr,int target,int start,int end){
    int mid=(start+end)/2;
    if(start>end){
        return -1;
    }
    if(arr[mid]==target){
        return mid;
    }
    else if(target<arr[mid]){
        return Binary_Search_rec(arr,target,start,mid-1);
    }
    else{
        return Binary_Search_rec(arr,target,mid+1,end);
    }
}
int main(){
    vector<int>arr={1,2,3,4,5,6};
    cout<<Binary_Search_rec(arr,6,0,arr.size()-1)<<endl;
}