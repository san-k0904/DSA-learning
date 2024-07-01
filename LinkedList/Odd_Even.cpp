#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=NULL;
        }
};
class List{
    public:
    Node* head;
    Node* tail;
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        Node* temp= new Node(val);
        if(head==NULL && tail==NULL){
            head=tail=temp;
        }
        temp->next=head;
        head=temp;
    }
    void push_back(int val){
        Node* temp=new Node(val);
        if(head==NULL && tail==NULL){
            head=tail=temp;
        }
        tail->next=temp;
        tail=temp;
    }
    void pop_back(){
        if(head==NULL){
            return;
        }
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    void pop_front(){
        if(head==NULL){
            return;
        }
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void insert(int pos,int ele){
        if(head==NULL){
            cout<<"No such position in ll yet.";
            return;
        }
        Node* newNode= new Node(ele);
        Node* prev=NULL;
        Node* curr=head;
        while(pos!=1 && curr!=NULL){
            prev=curr;
            curr=curr->next;
            pos--;
        }
        if(pos!=1){
            cout<<"No such position in ll yet.";
            return;
        }
        else{
            if(prev!=NULL){
                prev->next=newNode;
                newNode->next=curr;
                if(prev==tail){
                    tail=newNode;
                }
            }
            else{
                newNode->next=head;
                head=newNode;
            }
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
};

Node* odd_EvenList(Node* head){
    if(!head){
        return head;
    }
    List even;
    List odd;
    Node* temp=head;
    while(temp){
        if((temp->data & 1)==0){
            even.push_back(temp->data);
        }
        else{
            odd.push_back(temp->data);
        }
        temp=temp->next;
    }
    (even.tail)->next=odd.head;
    if(even.head){
        return even.head;
    }else{
        return odd.head;
    }
}
int main(){
    List ll;
    
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(8);
    ll.push_back(6);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(7);

    ll.printList();
    ll.head=odd_EvenList(ll.head);
    ll.printList();
    return 0;
}