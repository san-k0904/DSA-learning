#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void StockSpan(vector<int>stock,vector<int>& span,stack<int>& s,int i){
    if(i==stock.size()){
        return;
    }
    if(s.empty()){
        span[i]=i+1;
        s.push(i);
        StockSpan(stock,span,s,i+1);
    }
    else{
        if(stock[s.top()]<=stock[i]){
            s.pop();
            StockSpan(stock,span,s,i);
        }
        else{
            span[i]=i-s.top();
            s.push(i);
            StockSpan(stock,span,s,i+1);
        }

    }

}
int main(){
    stack<int>s;
    vector<int>stock={100,80,60,70,60,85,100};
    vector<int>span(7,0);
    StockSpan(stock,span,s,0);
    for(int i:span){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}