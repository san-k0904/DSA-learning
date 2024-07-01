#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextGreater(vector<int> original, vector<int>& ans){
    stack<int> s;
    ans[original.size()-1]=-1;
    s.push(original.back());
    for(int i=original.size()-2;i>=0;i--){
        while(!s.empty()&& s.top()<=original[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(original[i]);
    }
}
int main(){
    vector<int> original={6,8,0,1,3};
    vector<int> ans(original.size(),0);

    nextGreater(original,ans);
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}