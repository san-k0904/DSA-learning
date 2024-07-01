#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool Duplicate_Parenthesis(string str){//according to the question the string will always be valid
    stack<char> s;
    for(char ch:str){
        if(ch!=')'){//given in question only this is to be used
            s.push(ch);
        }
        else{
            if(s.top()=='('){
                return true;//means duplicate is there
            }
            else{
                while(s.top()!='('){
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return false;//didn't check for stack empty case coz question said it will be valid string and 
    //and even if there is (a+b)*c so * c would still be in stack but that doesn't matter
}
int main(){
    string str="((a+b)+c)*z";
    if(Duplicate_Parenthesis(str)){
        cout<<"Duplicate Parenthesis present\n";
    }
    else{
        cout<<"Duplicate Parenthesis not present\n";
    }
}