#include<iostream>
using namespace std;
bool closeStrings(string word1, string word2) {
    if(word1.length()!=word2.length())
        return false;
    int frequency1[26]={0};
    int frequency2[26]={0};
    for(int i=0;i<word1.length();i++){
        frequency1[word1[i]-'a']++;
        frequency2[word2[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(frequency1[i]!=frequency2[i]){
            if(frequency2[i]==0||frequency1[i]==0){
                return false;
            }
            int flag=0;
            for(int j=i+1;j<26;j++){
                if(frequency2[j]==frequency1[i]){
                    flag=1;
                    swap(frequency2[i],frequency2[j]);
                    break;
                }
            }
            if(flag==0)
                return false;
        }
    }
    return true;
}
int main(){
    string original,checkString;
    cout<<"Enter your String: ";
    getline(cin,original);//can give delimiter...optional
    cout<<"Enter another String: ";
    getline(cin,checkString);
    cout<<(boolalpha)<<closeStrings(original,checkString)<<"\n";
    return 0;
}