#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }

    // ~Node() {
    //     if(next != NULL) {
    //         delete next;
    //         next = NULL;
    //     }
    // }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insert(int val, int pos) {
        if(pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        int i=0;
        while(temp != NULL && i<pos-1) {
            temp = temp->next;
            i++;
        }

        if(temp == NULL) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if(head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if(head == NULL) { //0 els
            return;
        }
        if(head->next == NULL) { //1 el
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        //temp has tail's prev
        temp->next = NULL;
        
        delete tail;
        tail = temp;
    }

    // ~List() {
    //     if(head != NULL) {
    //         delete head; 
    //         head = NULL; 
    //     }
    // }  
};
Node* deleteAfter(Node* head,int m,int n){
    Node* temp=head;
    while(temp){
        for(int i=0;i<m-1;i++){//coz we start from head so if m=2 means 1 for head and 2 for head->next so total m-1 times run
            temp=temp->next;//coz temp goes to next when loop ends so m-2 call will make temp go to m-1 and
                            // since we started from 0 this is correct
            if(!temp){
                return head;
            }
        }
        Node* curr=temp->next;
        
        for(int i=0;i<=n-1 && curr;i++){//since we already are starting from node to delete so if n=2 it has to run 2 times so 0-n-1 i.e. <=n-1
            Node* next=curr->next;
            curr->next=NULL;
            delete curr;
            curr=next;
            
        }
        temp->next=curr;
        temp=temp->next;
    }
    return head;
}

int main(){
    List ll;
    
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
    ll.printList();
    cout<<"After deletion:\n";
    ll.head=deleteAfter(ll.head,m,n);
    ll.printList();
    return 0;
}