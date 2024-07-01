#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void PrintList(list<int>ll){
    list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL\n";
}
void deleteAfter(list<int>& ll, int m, int n) {
    if (ll.empty()) {
        return;
    }

    list<int>::iterator safe;
    if (m == 0) {
        safe = ll.begin();
    } else if (m > ll.size()) {
        return; 
    } else {
        safe = ll.begin();
        advance(safe, m - 1); //point to the m-th node
    }

    while (n-- > 0 && safe!= ll.end()) {
        list<int>::iterator delNext = safe;
        advance(delNext, 1);
        if (delNext == ll.end()) {
            break; //reached the end of the list now stop deleting
        }
        ll.erase(delNext);
    }
}

int main(){
    list<int> ll;
    
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    int m,n;
    cout<<"Enter after which position you want to begin deleting: ";
    cin>>m;
    cout<<"Enter how many to delete: ";
    cin>>n;
    PrintList(ll);
    cout<<"After deletion:\n";
    deleteAfter(ll,m,n);
    PrintList(ll);
    return 0;
}