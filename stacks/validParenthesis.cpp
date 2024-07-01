#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool validParenthesis(string str){
    stack<char> s;
    for(char ch:str){
        if(ch=='('||ch=='{'||ch=='['){//longer code to ensure that time complexity is less
            s.push(ch);
        }
        else if(ch==')'||ch=='}'||ch==']'){
            if(s.empty()){
                return false;
            }
            if((ch==')'&& s.top()=='(')||
            (ch=='}'&& s.top()=='{')||
            (ch==']'&& s.top()=='[')){
                    s.pop();
            }
            else{
                return false;
            }
        }
    }
    if(!s.empty()){
        return false;
    }
    return true;//all the 3-4 lines can be reduced to 
    //return s.empty();
}
int main(){
    string str= "){[(]}";
    if(validParenthesis(str)){
        cout<<"Valid Parenthesis\n";
    }
    else{
        cout<<"Not valid\n";
    }
    return 0;
}