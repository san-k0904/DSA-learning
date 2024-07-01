#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0)
        return 1;
    return n*factorial(n-1);
}
int main(){
    int n,r;
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"Enter value of r: ";
    cin>>r;
    int result= (factorial(n))/((factorial(r))*factorial(n-r));
    cout<<"The result of "<<n<<"C"<<r<<" is: "<<result<<endl;
    return 0;
}