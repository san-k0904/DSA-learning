#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
    return a.second < b.second; //coz we sorting in ascending order
}

int MaxActivities(vector<int>start, vector<int> end){
    
    vector<pair<int,int>> activity(start.size(),{0,0});//OR we could just not initialize it and directly push_back
    //vector<pair<int,int>> activity(start.size(),make_pair(0,0));
    for(int i=0;i<start.size();i++){
        activity[i]={start[i],end[i]};//If Index represented Activity number then we can make tuple with index too
    }
    sort(activity.begin(),activity.end(),compare);
    

    int count=1;//coz we always consider our first elt as one necessary for max activities
    int currEnd=activity[0].second;
    for(int i=1;i<activity.size();i++){
        if(currEnd<=activity[i].first){
            count++;
            currEnd=activity[i].second;
        }
    }
    return count;
}
int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};

    cout<<MaxActivities(start,end)<<endl;
    return 0;
}