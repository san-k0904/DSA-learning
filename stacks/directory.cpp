#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

/* USING STACK...
string simplifyPath(string path) {
    string output;
    stack<string>st;
    int i=0;
    int n=path.size();
    while(i<n){
        while(path[i]=='/'){
            i++;
        }
        while(path[i] && path[i]!='/'){
            output+=path[i];
            i++;
        }
        if(output==".." && !st.empty()){
            st.pop();
        }
        else if(output.size() && output!="." && output!=".."){
            st.push(output);
        }
        output.clear();
    }
    while(!st.empty()){
        output="/"+st.top()+output;
        st.pop();
    }
    if(!output.size()){
        output="/";
    }
    return output;
}
*/

//USING VECTOR 

string simplifyPath(string path) {
    string output;
    vector<string>output_path;
    int i=0;
    while(i<path.size()){
        while(path[i]=='/'){
            i++;
        }
        while(path[i] && path[i]!='/'){
            output+=path[i];
            i++;
        }
        if(output==".." && output_path.size()){
            output_path.pop_back();
        }
        else if(output.size() && output!=".." && output!="."){
            output_path.push_back(output);
        }
            output.clear();
    }
    output="/";
    int n=output_path.size();
    for(int i=0;i<=n-2;i++){
        output+=output_path[i];
        output+="/";
    }
    if(n>0){
        output+=output_path[n-1];
    }

    return output;
}