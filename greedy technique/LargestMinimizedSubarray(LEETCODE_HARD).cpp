#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int subarr_lessThanMid(vector<int>& nums, int mid){
    int sum =0;
    int count=1;//at least 1 subarray
    for(int i=0;i<nums.size();i++){
        if(sum+nums[i]>mid){
            sum=nums[i];//start sum from the element for new subarray
            count++;
        }
        else{
            sum+=nums[i];
        }
    }
    return count;

}
int splitArray(vector<int>& nums, int k) {
    int ans;
    int low= *max_element(nums.begin(),nums.end());
    int high= accumulate(nums.begin(),nums.end(),0);
    while(low<=high){//coz if we see the minimum largest value possible is the largest element in arr while maximum 
    //largest will be when k=1 i.e. sum of all
        int mid= low+((high-low)/2);
        int n= subarr_lessThanMid(nums, mid);
        if(n>k){//so we check if it's possible that our array can be split such that it's max is less than or greater than mid
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}