#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseString(string str){
    string ans;
    stack<char> s;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        ans+= s.top();
        s.pop();
    }
    return ans;
}
int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    string result=reverseString(str);
    cout<<result<<endl;
    return 0;
}