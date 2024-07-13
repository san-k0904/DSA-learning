#include<iostream>
#include<vector>
using namespace std;

int MinCoins(vector<int> coins, int V){
    int count=0;
    for(int i=coins.size()-1;i>=0;i--){
        if(coins[i]<=V){//if bigger they will automatically be skipped
            count+= V/coins[i];
            V=V%coins[i];
        }
    }
    return count;
}

int main(){
    vector<int> coins={1,2,5,10,20,50,100,500,2000};//sort the coins if not already sorted and always go from large to small value
    cout<<MinCoins(coins,121)<<endl;
    return 0;
}