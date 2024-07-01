#include<iostream>
using namespace std;
#include<vector>
int maxArea(vector<int>& height) {//this one is not dealing with -ve heights as this was also accepted in leetcode
        int n=height.size();
        int start=0, end=n-1;
        int maxAmountWater=0;
        while(start<end){
            maxAmountWater=max(maxAmountWater,(min(height[start],height[end])*(end-start)));
            if(height[start]<height[end])
                start++;
            else
                end--;
        }
        return maxAmountWater;
}
int main(){
    vector<int> height;
    int n;
    cout<<"Enter the size of data: ";
    cin>>n;
    cout<<"Enter heights: ";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        height.push_back(temp);
    }
    cout<<"Maximum water holding area is: "<<maxArea(height)<<"\n";
    return 0;
}