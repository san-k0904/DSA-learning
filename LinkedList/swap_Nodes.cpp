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
Node* swapNodes(Node* head, int x, int y){
    if(!head){
        cout<<"No nodes\n";
        return head;
    }
    Node* prev1=NULL;
    Node* curr1=head;
    Node* next1=curr1->next;

    Node* prev2=NULL;
    Node* curr2=NULL;
    Node* next2=NULL;

    int found=0;
    while( curr1 && curr1->data!=x && curr1->data!=y){
        prev1=curr1;
        curr1=curr1->next;
        if(curr1){
            next1=curr1->next;
        }
        
    }
    if(!curr1){
        cout<<"elements not available\n";
        return head;
    }
    else{
        curr2=curr1->next;
        prev2=curr1;
        while(curr2 && curr2->data!=y && curr2->data!=x){
            prev2=curr2;
            curr2=curr2->next;
            if(curr2){
                next2=curr2->next;
            }
        }
        if(!curr2){
            if(curr1->data==x){
                cout<<"No such element "<<y<< " available\n";
            }
            else{
                cout<<"No such element "<<x<< " available\n";
            }
        return head;
        }
    }

    prev1->next=curr2;
    curr2->next=next1;

    prev2->next=curr1;
    curr1->next=next2;

    return head;
}
int main(){
    List ll;
    
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(8);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(4);

    int x,y;
    cout<<"Enter value of x: ";
    cin>>x;
    cout<<"Enter value of y: ";
    cin>>y;
    ll.printList();
    ll.head=swapNodes(ll.head,x,y);
    ll.printList();
    return 0;
}
