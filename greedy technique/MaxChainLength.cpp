#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
    return a.second < b.second; //coz we sorting in ascending order
}

int maxChainLength(vector<pair<int,int>>pairs){
    
    sort(pairs.begin(),pairs.end(),compare);
    

    int count=1;//coz we always consider our first elt as one necessary for max activities
    int currEnd=pairs[0].second;
    for(int i=1;i<pairs.size();i++){
        if(currEnd<=pairs[i].first){
            count++;
            currEnd=pairs[i].second;
        }
    }
    return count;
}
int main(){
    vector<pair<int,int>>pairs={{5,24},{39,60},{5,28},{27,40},{50,90}};

    cout<<maxChainLength(pairs)<<endl;
    return 0;
}