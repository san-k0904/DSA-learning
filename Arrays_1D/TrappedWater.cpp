#include<iostream>
using namespace std;
int TrappedWater(int height[],int n){
    int leftmax[n];
    int rightmax[n];
    int width=1;
    leftmax[0]=height[0];//coz INT_MAX - any number = +ve number in c++
    rightmax[n-1]=height[n-1];
    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],height[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],height[i+1]);
    }
    int waterTrapped=0;
    for(int i=0;i<n;i++){
        int currentWater;
        currentWater= (min(leftmax[i],rightmax[i]))-height[i];
        if(currentWater>0){//value can come negative in cases where the current bar is higher than it;s right and left so in that case on top of it no water should be present;
            waterTrapped+=currentWater;
        }
    }
    return (waterTrapped*width);
}

int main(){
    int n;
    cout<<"Enter number of data: ";
    cin>>n;
    int height[n];
    cout<<"Enter Value: ";
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<TrappedWater(height,n)<<"\n";
    return 0;
}