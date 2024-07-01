#include<iostream>
#include<vector>
#include<string>
using namespace std;
void AllCombinations(vector<vector<char>> keypad, string digits, string sol){
    if(digits.size()==0){
        cout<<sol<<" ";
        return;
    }
    int idx=digits[0]-'0';
    for(char ch: keypad[idx]){
        AllCombinations(keypad,digits.substr(1),sol+ch);
    }
}

int main(){
    vector<vector<char>> keypad={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    string digits;
    cout<<"Enter number: ";
    getline(cin,digits);
    AllCombinations(keypad,digits,"");
    cout<<endl;
    return 0;
}