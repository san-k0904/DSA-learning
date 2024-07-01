#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    int n= nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> triplets;
    for(int first=0;first<n;first++){
        if(first > 0&& nums[first]==nums[first-1]){
            continue;
        }
        int sec=first+1;
        int third=n-1;
        int sum=0;
        while(sec<third){
            sum=nums[first]+nums[sec]+nums[third];
            if(sum<0){
                sec++;
            }
            else if(sum>0){
                third--;
            }
            else{
                triplets.push_back({nums[first],nums[sec],nums[third]});
                sec++;
                third--;
                while(sec<third && nums[sec]==nums[sec-1]){
                    sec++;
                }
                while(sec<third && nums[third]==nums[third+1]){
                    third--;
                }
            }
        }
        
    }
    return triplets;
}
int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the size of data: ";
    cin>>n;
    cout<<"Enter numbers: ";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    vector<vector<int>>tripletSum=threeSum(nums);
    for(int i=0;i<tripletSum.size();i++){
        cout<<"[";
        for(int j=0;j<tripletSum[i].size();j++){
            cout<<tripletSum[i][j]<<",";
        }
        cout<<"],\n";
    }
    return 0;
}