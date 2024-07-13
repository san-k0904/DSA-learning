#include<iostream>
#include<string>
using namespace std;

string getSmallestString(int n, int k) {
    string smallestStr;
    while(n!=0){
        int ch= k-(n-1)*26;// we do k-(n-1)*26 coz for that 1 place we have to find the smallest possible value
        if(ch<=0){
            smallestStr.push_back('a');
            n--;
            k--;
        }
        else{
            smallestStr.push_back(ch+'a'-1);//coz originally they aren't 1 indexed
            n--;
            k=k-ch;
        }
    }
    return smallestStr;

}