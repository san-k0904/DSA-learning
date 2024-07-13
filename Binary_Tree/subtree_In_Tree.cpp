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
bool isIdentical(NODE<int>* root1,NODE<int>* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL||root2==NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);    
}

bool isSubtree(NODE<int>* root,NODE<int>* subroot){
    if(root==NULL){//in isSubtree we just need to ensure base case is if root turns NULL

        return subroot==NULL;//we will only get true when isIdentical returns true coz otherwise subroot remains at start position
        //unless subroot is also NULL

    }//the case where root might not be NULL but subroot is NULL is checked in isIdentical...
    //also we are not moving subroot in isSubtree recursion anyway

    if(root->data==subroot->data){
        if(isIdentical(root,subroot)){
            return true;
        }//otherwise there might still be a possibility that this node exists somewhere else
    }
    bool CheckLeft= isSubtree(root->left,subroot);
    if(!CheckLeft){
        return isSubtree(root->right,subroot);
    }

    return true;//in case in CheckLeft itself we already got true value then no need to check for right
}
int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);
    NODE<int>* subroot=new NODE(2);
    subroot->left=new NODE(4);
    subroot->right=new NODE(5);

    cout<<(boolalpha)<<isSubtree(root,subroot)<<endl;
    return 0;
}