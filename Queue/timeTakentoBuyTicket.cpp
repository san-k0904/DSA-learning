#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    queue<pair<int,int>> q;//O(n+k)
    for(int i=0;i<tickets.size();i++){
        q.push({i,tickets[i]});
    }
    int time=0;
    while(!q.empty()){
        auto [i,ticket]=q.front();
        ticket--;
        time++;
        q.pop();
        if(i==k && ticket==0){
            return time;
        }
        if(ticket>0){
            q.push({i,ticket});
        }
    }
    return time;

    // int time=0;//more efficient code O(n)
    //     for(int i=0;i<tickets.size();i++){
    //         if(i<=k){
    //             time+=min(tickets[i],tickets[k]); //+= coz say if it is 2 3 2 4 then time for k=2 would be (1+1+1+1)+(1+1+1)=2+2+2+1
    //         }
    //         else{
    //             time+=min(tickets[i],tickets[k]-1);
    //         }
    //     }
    //     return time;
}
int main(){
    vector<int> tickets={2,3,2};
    int time= timeRequiredToBuy(tickets, 2);
    cout<<time<<endl;
}