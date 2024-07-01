#include<iostream>
#include<cmath>
using namespace std;
int decimalTobinary(int decimal){
    int powerTen=1;
    int binary=0;
    while(decimal>0){
        binary+=(decimal%2)*powerTen;
        powerTen*=10;
        decimal/=2;
    }
    return binary;
    
}
int main(){
    int decimal;
    cout<<"Enter decimal number: ";
    cin>>decimal;
    int binary;
    binary=decimalTobinary(decimal);
    cout<<binary<<"\n";
    return 0;
}