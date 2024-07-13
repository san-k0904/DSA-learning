#include<iostream>
#include<vector>
#include<queue>
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
int SumNodes(NODE<T>* root){
    if(root==NULL){
        return 0;
    }
    int leftSum= SumNodes(root->left);
    int rightSum= SumNodes(root->right);
    return leftSum+rightSum+root->data;
}
int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);
    cout<<SumNodes(root)<<"\n";
    return 0;
}