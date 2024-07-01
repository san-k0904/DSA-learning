#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void leftsmallest(vector<int>heights,vector<int>& leftsmall){
    stack<int>s;
    leftsmall[0]=-1;
    s.push(0);//index
    for(int i=1;i<heights.size();i++){
        while(!s.empty() && heights[s.top()]>=heights[i] ){//remember s.empty should be checked first
            s.pop();
        }
        if(s.empty()){
            leftsmall[i]=-1;
        }
        else{
            leftsmall[i]=s.top();
        }
        s.push(i);
    }
}
void rightsmallest(vector<int>heights,vector<int>& rightsmall){
    stack<int>s;
    rightsmall[heights.size()-1]=heights.size();
    s.push(heights.size()-1);//index
    for(int i=heights.size()-2;i>=0;i--){
        while(!s.empty() && heights[s.top()]>=heights[i]){//remember s.empty should be checked first
            s.pop();
        }
        if(s.empty()){
            rightsmall[i]=heights.size();//always put n when stack is empty
        }
        else{
            rightsmall[i]=s.top();
        }
        s.push(i);
    }
}

int maxArea_Histogram(vector<int>heights,vector<int> rightsmall, vector<int> leftsmall){
    int maxArea=INT_MIN;
    for(int i=0;i<heights.size();i++){
        int width=(rightsmall[i]-leftsmall[i]-1)*1;//default width is 1 hence *1
        int currArea=heights[i]*width;
        maxArea=max(maxArea,currArea);
    }
    return maxArea;
}

int main(){
    vector<int>heights={2,1,5,6,2,3};
    vector<int>leftsmall(heights.size());//have to initialise soz we directly use last element
    vector<int>rightsmall(heights.size());//have to initialise soz we directly use last element
    leftsmallest(heights,leftsmall);
    rightsmallest(heights,rightsmall);
    cout<<maxArea_Histogram(heights,rightsmall,leftsmall)<<endl;
    return 0;
}