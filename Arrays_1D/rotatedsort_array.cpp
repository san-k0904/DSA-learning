#include<iostream>
using namespace std;

int RotatedArray_Search(int arr[],int n,int target){//we don't get the index at which it is roatated coz that is supposed to be unknown and we don't have to write code to roatate it just take an example
    int low=0;
    int high= n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else{
            if(arr[low]<arr[mid]){//left sorted array
                if(target<arr[mid]&& target>=arr[low]){//means the value lies on the left side only
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            else{//right sorted array
                if(target>arr[mid]&& target<=arr[high]){//means the value lies on the right side of mid
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int random_rotated_array[]={6,7,8,0,1,2,3,4,5};//sorted array which is randomly rotated at an index and placed at front
    int n=sizeof(random_rotated_array)/sizeof(int);
    int target;
    cout<<"Enter target: ";
    cin>>target;
    cout<<RotatedArray_Search(random_rotated_array,n,target)<<"\n";
    return 0;
}