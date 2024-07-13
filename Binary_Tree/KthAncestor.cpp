#include<iostream>
#include<vector>
using namespace std;

template<class T>
class NODE{
public:
    T data;
    NODE* left;
    NODE* right;

    NODE(T data){
        this->data=data;
        left=right=NULL;
    }

};
static int idx=-1;
template<class T>
NODE<T>* createTree(vector<T>& nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    NODE<T>* currNode= new NODE<T>(nodes[idx]);
    currNode->left=createTree(nodes);
    currNode->right=createTree(nodes);

    return currNode;
}

template<class T>
int KthAncestor(NODE<T>* root,int nodeval,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==nodeval){//means we have reached the node now find kth ancestor
        return 0;
    }
    int leftDist=KthAncestor(root->left,nodeval,k);
    int rightDist=KthAncestor(root->right,nodeval,k);

    if(leftDist==-1 && rightDist==-1){
        return -1;
    }
    int Validval = leftDist==-1 ? rightDist : leftDist;
    if(Validval+1==k){//coz once we reach the node whose ancestor we have to find...it will return 0
    //and go back to ancestor but according to us that node is counted as 1st ancestor...so we are 1 behind
        cout<<"Kth ancestor is: "<<root->data<<endl;
    }

    return Validval+1;
}

int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);
    KthAncestor(root,4,2);
    return 0;
}