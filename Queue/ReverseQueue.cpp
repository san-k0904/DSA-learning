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

template<class T>
void reverseQueue(queue<T>& original){
    stack<T> s;
    while(!original.empty()){
        s.push(original.front());
        original.pop();
    }
    while(!s.empty()){
        original.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> initial;
    for(int i=1;i<=10;i++){
        initial.push(i);
    }
    reverseQueue(initial);
    PrintQueue(initial);
    return 0;
}