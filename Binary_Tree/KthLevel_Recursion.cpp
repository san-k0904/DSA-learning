#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
void KthHelper(NODE<T>* root,int k,int currLvl){
    if(root==NULL){
        return;
    }
    if(currLvl==k){
        cout<<root->data<<" ";
        return;
    }
    KthHelper(root->left,k,currLvl+1);
    KthHelper(root->right,k,currLvl+1);
}
template<class T>
void Kthlevel(NODE<T>*root, int k){//Many times we are already given fn with 2 val...
                                    //if we want more just make some sort of helper fn

    KthHelper(root,k,1);//O(N)
}
int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);

    Kthlevel(root,3);
    return 0;
}