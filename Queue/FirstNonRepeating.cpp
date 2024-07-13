#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

void FirstNonRepeating(string str){
    vector<int> freq(26,0);
    queue<char> q;
    for(char ch: str){
        q.push(ch);
        freq[ch-'a']++;
        while(!q.empty() && freq[q.front()-'a']>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1\n";
        }
        else{
            cout<<q.front()<<endl;
        }
    }
}
int main(){
    string str= "aabccxb";
    FirstNonRepeating(str);
    return 0;
}