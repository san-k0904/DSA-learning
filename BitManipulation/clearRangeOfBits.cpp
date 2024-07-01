#include<iostream>
using namespace std;

int ClearRange(int nums,int i,int j){
    int a= ~0<<j+1;
    int b=(1<<i)-1;
    int mask=a|b;
    nums=nums & mask;
    return nums;
}