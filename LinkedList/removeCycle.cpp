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

void removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            isCycle = true;
            break;
        }
    }

    if(!isCycle) {
        return;
    }

    //Removing Loop
    slow = head;

   if(slow == fast) { 
    //special case when tail is connected to head
        while(fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;

   } else {
        Node* prev = fast;
        while(slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }

        //prev is the last node
        prev->next = NULL;
   }
}
int main(){
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.tail->next = ll.head; //creating a cycle
    removeCycle(ll.head);
    ll.printList(); 
    return 0;
}