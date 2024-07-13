#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<class T>
void PrintQueue(queue<T> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}


void reverseFirst_K(queue<int>& q,int k){
    if(k==0){
        return;
    }

    stack<int> s;
    int n= q.size();
    int count=0;
    while(count!=k && !q.empty()){//since count starting from 0 so even when coz of count++=k we would have moved k steps 
        s.push(q.front());
        q.pop();
        count++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(count<n){
        q.push(q.front());
        q.pop();
        count++;
    }
}
int main(){
    queue<int>q;
    for(int i=1;i<=10;i++){
        q.push(i);
    }
    reverseFirst_K(q,4);
    PrintQueue(q);
    return 0;
}