#include<iostream>
#include<list>
#include<stack>
#include<iterator>
using namespace std;

template <class T>
bool checkPalindrome(list<T> li){
    typename list<T>::iterator i;//typename is added for templated iterator
    stack<T> s;

    for(i=li.begin();i!=li.end();i++){//the < or > operator isn't present in list so we use !=
        s.push(*i);
    }
    for(i=li.begin();i!=li.end() && !s.empty();i++){
        if(s.top()!=(*i)){
            return false;
        }
        s.pop();
    }
    return true;
}

int main(){
    list<int> li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(2);
    li.push_back(1);
    cout<<(boolalpha)<<checkPalindrome(li)<<endl;
    return 0;
}