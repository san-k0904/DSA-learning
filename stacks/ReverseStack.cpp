#include<iostream>
#include<stack>
using namespace std;

template<class T>
void pushAtBottom(stack<T>& s,T val){
    if(s.empty()){
        s.push(val);
        return;
    }
    T temp=s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);
}
template<class T>
void printStack(stack<T> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
template<class T>
void reverseStack(stack<T>& s){
    if(s.empty()){
        return;
    }
    T temp= s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,temp);
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    printStack(s);
    reverseStack(s);
    printStack(s);
    return 0;

}