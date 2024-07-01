#include<iostream>
#include<vector>
using namespace std;

int CountofMerge(vector<int>& nums,int si,int ei,int mid){
    int i=si;
    int j=mid+1;
    int count=0;
    vector<int> temp;
    while(i<=mid && j<=ei){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i++]);
        }
        else{
            count+=mid-i+1;//the ith index is also included hence +1
            temp.push_back(nums[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(nums[i++]);
    }
    while(j<=ei){
        temp.push_back(nums[j++]);
    }
    for(int i=si,k=0;i<=ei;i++){
        nums[i]=temp[k++];
    }
    return count;
}
int divideToSmaller_MergeSort(vector<int>& nums,int si,int ei){
    int count=0;
    if(si>=ei){
        return count;
    }
    int mid= si+(ei-si)/2;
    count=divideToSmaller_MergeSort(nums,si,mid);//fix count of left
    count+=divideToSmaller_MergeSort(nums,mid+1,ei);//add count of right
    count+=CountofMerge(nums,si,ei,mid);//add count that we get on merging
    return count;
}
int main(){
    vector<int> nums={2,4,3,5,1};
    cout<<divideToSmaller_MergeSort(nums,0,nums.size()-1)<<endl;
    return 0;
}