#include<iostream>
#include<queue>
using namespace std;

template<class T>
void Interleave( queue<T>& initial){//given that initial will always be even size

    int n=initial.size();
    
    queue<T>firstHalf;

    for(int i=0;i<n/2;i++){
        firstHalf.push(initial.front());
        initial.pop();
    }
    for(int i=0;i<n/2;i++){
        initial.push(firstHalf.front());// ensuring only one extra queue is used at max
        initial.push(initial.front());
        firstHalf.pop();
        initial.pop();
    }

}
template<class T>
void PrintQueue(queue<T> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> initial;
    for(int i=1;i<=10;i++){
        initial.push(i);
    }
    Interleave(initial);
    PrintQueue(initial);
    return 0;
}