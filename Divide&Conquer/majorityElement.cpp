#include<iostream>
#include<vector>
using namespace std;

int CountinRange(int arr[],int lo,int hi, int num){
    int count=0;
    for(int i=lo;i<=hi;i++){
        if(arr[i]==num){
            count++;
        }
    }
    return count;

}

int divideToSmaller(int arr[],int lo,int hi){
    if(lo==hi){
        return arr[lo];
    }
    int mid= lo+(hi-lo)/2;
    int left= divideToSmaller(arr,lo,mid);
    int right=divideToSmaller(arr,mid+1,hi);
    if(left==right){//if both the elements is same
        return left;
    }
    int leftCount=CountinRange(arr,lo,hi,left);
    int rightCount=CountinRange(arr,lo,hi,right);
    return leftCount > rightCount? left:right;

}

int main(){
    int arr[]={3,2,3};
    cout<< divideToSmaller(arr,0,2)<<endl;
    return 0;
}