#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2!=0)
            cout<<"1";
        for(int j=1;j<=i/2;j++)
            cout<<"01";
        cout<<endl;
    }
    return 0;
}