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
NODE<T>* LCA2(NODE<T>*root,T n1,T n2){//O(N) and O(1)

    if(root==NULL){
        return NULL;
    }

    if(root->data==n1||root->data==n2){
        return root;
    }

    NODE<T>* LeftLCA= LCA2(root->left,n1,n2);
    NODE<T>* RightLCA= LCA2(root->right,n1,n2);
    
    if(LeftLCA!=NULL && RightLCA!=NULL){//means the current position is my LCA
        return root;
    }
    return LeftLCA==NULL? RightLCA : LeftLCA;//covers all 3 cases where left=right=NULL or any one of them is valid 
    //while other is null
}
template<class T>
int dist(NODE<T>* root, T n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int leftDist= dist(root->left, n);
    if(leftDist!=-1){
        return leftDist+1;
    }
    int rightDist= dist(root->right, n);
    if(rightDist!=-1){
        return rightDist+1;
    }

    return -1;//mean leftDist and RightDist both were -1
}

template<class T>
int minDist(NODE<T>*root, T n1, T n2){
    NODE<T>*lca= LCA2(root,n1,n2);
    int dist1= dist(lca,n1);
    int dist2= dist(lca,n2);

    return dist1+dist2;
}
int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);

    cout<<minDist(root,4,5)<<endl;
    return 0;
}