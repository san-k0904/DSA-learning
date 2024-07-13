#include<iostream>
#include<string>
using namespace std;

string largestOddNumber(string num) {
    string largestOdd="";
    for(long long i=num.size()-1;i>=0;i--){
        if((num[i]-'0')&1){
            largestOdd=num.substr(0,i+1);
            break;
        }
    }
    return largestOdd;

}