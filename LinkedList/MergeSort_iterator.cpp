#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void PrintList(list<int> ll){
    list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout<< (*itr)<<"->";
    }
    cout<<"NULL\n";
}

void mergeSort(list<int>& ll){
    if(ll.size()<=1){
        return;
    }
    list<int>left,right;
    list<int>::iterator mid=ll.begin();
    advance(mid,ll.size()/2);//move mid to middle
    left.splice(left.begin(),ll,ll.begin(),mid);//since left.begin currently points only to NULL so values from ll fit properly
    right.splice(right.begin(),ll,mid,ll.end());//since right.begin currently points only to NULL so values from ll fit properly

    mergeSort(left);
    mergeSort(right);

    ll.clear();

    ll.merge(left);
    ll.merge(right);
}
int main(){
    list<int> ll;
    ll.push_back(5);
    ll.push_back(3);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(4);
    cout<<"List before merge sort:\n";
    PrintList(ll);
    cout<<"List after merge sort:\n";
    mergeSort(ll);
    PrintList(ll);
    return 0;
}