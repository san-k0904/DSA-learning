#include<iostream>
#include<vector>
using namespace std;
void AllOccur(vector<int>& arr,int key,int i){
    static int flag=0;
    if(i==arr.size()){
        if(flag==0)
            cout<<"The number is not present";
        cout<<endl;
        return;
    }
    if(arr[i]==key){
        flag = 1;
        cout<<i<<", ";
    }
    return AllOccur(arr,key,i+1);
}
int main(){
    vector<int> arr={1,2,3,2,4,5,2};
    AllOccur(arr,2,0);
    return 0;
}