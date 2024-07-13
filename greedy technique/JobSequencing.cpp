#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int,int>j1,pair<int,int>j2){
    return j1.second > j2.second; // Descending -> ">"
}

int maxProfit(vector<pair<int,int>>Jobs){
    sort(Jobs.begin(),Jobs.end(),compare);
    int profit=Jobs[0].second;//we do the most profitable job
    int safeDeadline=2;//since in order to do 1 job we take 1 day/hr
    for(int i=1;i<Jobs.size();i++){
        if(Jobs[i].first>=safeDeadline){
            profit+=Jobs[i].second;
            safeDeadline++;//since only 1 day/hr to do the job
        }
    }
    return profit;
}
int main(){
    vector<pair<int,int>>Jobs={{4,20},{1,10},{1,40},{1,30}};
    cout<<maxProfit(Jobs)<<endl;
    return 0;
}