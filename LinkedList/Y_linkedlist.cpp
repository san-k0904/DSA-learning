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
};
int getSize(Node* head){
    if(head==NULL){
        return 0;
    }
    int size=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        size++;
    }
    return size;
}
Node* checkMerge(Node* l1head,Node* l2head ){
    int l1= getSize(l1head);
    int l2= getSize(l2head);
    Node* head1= l1head;
    Node* head2= l2head;
    if(l1>=l2){
        int diff= l1-l2;
        for(int i=0;i<diff;i++){
            head1=head1->next;
        }
    }
    else{
        int diff= l2-l1;
        for(int i=0;i<diff;i++){
            head2=head2->next;
        }
    }
    while(head1!=NULL && head2!=NULL && head1!=head2){
        head1=head1->next;
        head2=head2->next;

    }
    if(head1==NULL){
        return NULL;
    }else{

    return head1;
    
    }


}

int main(){
    List l1;
    List l2;

    l2.push_back(4);
    l2.push_back(5);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(6);
    l1.push_back(7);
    
    Node* temp=l1.head;
    while(temp->next!=l1.tail){
        temp=temp->next;
    }
    l2.tail->next=temp;
    l2.tail=l1.tail;

    Node* ans= checkMerge(l1.head,l2.head);
    cout<<"Ans is:"<<ans->data<<endl;

    return 0;
}