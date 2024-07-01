#include<iostream>
using namespace std;
#include<cmath>
int main(){
    int n,flag;
    cout<<"Enter number: ";
    cin>>n;
    for(int i=2;i<=n;i++){
        flag=0;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==1)
            continue;
        cout<<i<<" ";
    }
    return 0;
}