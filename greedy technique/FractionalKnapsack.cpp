#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<double,int>a,pair<double,int>b){
    return a.first > b.first; //coz we sorting in descending order based on ratio
}
double MaxValue(vector<int> value, vector<int> wt, int W){ //O(nlogn) coz of sort
    int n=value.size();
    vector<pair<double,int>> ratios(n,make_pair(0.0,0));//pair of ratio and it;s index for later accessing weight

    for(int i=0;i<n;i++){
        double ratio= value[i]/(double)wt[i];
        ratios[i]={ratio,i};
    }
    sort(ratios.begin(),ratios.end(),compare);
    double val=0;
    for(int i=0;i<n;i++){
        int idx= ratios[i].second;
        if(wt[idx]<=W){
            val+=value[idx];
            W= W-wt[idx];
        }
        else{
            double ratio= ratios[i].first;
            val+= ratio* W;
            W=0;
            break;
        }
    }
    return val;
}

int main(){
    vector<int>value={60,100,120};
    vector<int>weight={10,20,30};
    int Capacity=50;
    cout<<"Max Profit possible: "<<MaxValue(value,weight,Capacity)<<endl;
    return 0;
}