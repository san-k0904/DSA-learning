#include<iostream>
using namespace std;
int MaxProfit(int price[],int n){
    int bestBuy[n];
    bestBuy[0]=INT_MAX;
    for(int i=1;i<n;i++){
        bestBuy[i]=min(bestBuy[i-1],price[i-1]);//as buying price should come before selling price not on same day/index or after
    }
    int maxProfit=0;
    for(int i=0;i<n;i++){
        int currProfit=price[i]-bestBuy[i];
        maxProfit=max(maxProfit,currProfit);
    }
    return maxProfit;
}
int main(){
    int n;
    cout<<"Enter number of data: ";
    cin>>n;
    int price[n];
    cout<<"Enter Value: ";
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<MaxProfit(price,n)<<"\n";
    return 0;
}