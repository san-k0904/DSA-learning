#include<iostream>
#include<vector>
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
Node* mergeTwoSorted(Node* head1, Node* head2){
    List merged;
    Node* h1=head1;
    Node* h2=head2;
    while(h1 && h2){
        if(h1->data <= h2->data){
            merged.push_back(h1->data);
            h1=h1->next;
        }
        else{
            merged.push_back(h2->data);
            h2=h2->next;
        }
    }
    while(h1){
        merged.push_back(h1->data);
        h1=h1->next;
    }
    while(h2){
        merged.push_back(h2->data);
        h2=h2->next;
    }
    return merged.head;
}
Node* mergeK_Lists(vector<Node*> lists){
    if(lists.size()==0){
        return NULL;
    }
    if(lists.size()==1){
        return lists[0];
    }
    Node* head=lists[0];
    for(int i=1;i<lists.size();i++){
        head=mergeTwoSorted(head,lists[i]);
    }
    return head;
}