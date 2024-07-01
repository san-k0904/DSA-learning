#include<iostream>
#include<string>
using namespace std;
int countSubstr(string str,int i,int j){
    if(i==j){
        return 1;
    }
    if(i>j){
        return 0;
    }
    int res=countSubstr(str,i,j-1)+countSubstr(str,i+1,j)-countSubstr(str,i+1,j-1);
    if(str[i]==str[j]){
        res++;
    }
    return res;
}