#include<iostream>
#include<vector>
using namespace std;
vector<int> findErrorNums(vector<int>& nums){
    vector<int> result;
    vector<bool>isPresent(nums.size()+1,false);//make n+1 coz in nums no. is from 1-n so size of new should be n+1, initiate all to false
    for(int i=0;i<nums.size();i++){
        if(isPresent[nums[i]]){
            result.push_back(nums[i]);
        }
        isPresent[nums[i]]=true;
    }
    for(int i=1;i<isPresent.size();i++){
        if(!isPresent[i]){
            result.push_back(i);
            break;
        }
    }
    return result;
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
    vector<int>result=findErrorNums(nums);
    for(auto i:result){
        cout<<i<<", ";
    }
    cout<<"\n";
    return 0;
}