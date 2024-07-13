#include<iostream>
#include<string>
using namespace std;

int balancedStringSplit(string s) {
    int remaining=0;
    int total=0;
    for(char ch:s){
        if(ch=='R'){
            remaining++;
        }
        else{
            remaining--;
        }
        if(remaining==0){
            total++;
        }
    }
    return total;
}