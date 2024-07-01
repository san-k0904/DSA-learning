#include<iostream>
using namespace std;
int CountLowercase_Vowels(string str){
    string vowel="aeiou";
    int count=0;
    for(char ch:str){
        for(char vow:vowel){
            if(ch==vow){
                count++;
            }
        }
    }
    return count;
}
int main(){
    string str;
    cout<<"Enter your String: ";
    getline(cin,str);//can give delimiter...optional
    cout<<"Total no. of lower case vowels: "<<CountLowercase_Vowels(str)<<"\n";
}