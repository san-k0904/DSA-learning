#include<iostream>
#include<string>
#include<stack>
using namespace std;

string decodeString(string s) {
    string ans;
    stack<int> repetition;
    stack<string>express;
    int count=0;
    for(char ch:s){
        if(isdigit(ch)){
            count=count*10 +(ch-'0');//if it's 2 digit no.
        }
        else if(ch=='['){
            repetition.push(count);
            count=0;
            express.push(ans);//if suddenly new string begins
            ans="";
        }
        else if(ch==']'){
            string temp= ans;
            ans= express.top();
            int k=repetition.top();
            express.pop();
            repetition.pop();
            while(k>0){
                ans+=temp;
                k--;
            }
        }
        else{
            ans+=ch;
        }
    }
    return ans;
}