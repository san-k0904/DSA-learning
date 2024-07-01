#include<iostream>
#include<vector>
#include<string>
using namespace std;
void merge(string arr[],int si,int ei,int mid){
    vector<string> temp;
    int i=si,j=mid+1;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while (i<=mid){
        temp.push_back(arr[i++]);
    }
    while (j<=ei){
        temp.push_back(arr[j++]);
    }
    for(int i=si,k=0;i<=ei;i++){
        arr[i]=temp[k++];
    }
    

}

void mergesort(string arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    merge(arr,si,ei,mid);
}
int main(){
    string arr[]={"sun","earth","mars","mercury"};
    mergesort(arr,0,3);
    cout<<"Sorted array is: ";
    for(int i=0;i<=3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}