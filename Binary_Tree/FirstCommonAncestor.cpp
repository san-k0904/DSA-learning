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
bool rootToNodePath(NODE<T>* root, T n, vector<T>& path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    bool isLeft=rootToNodePath(root->left,n,path);
    bool isRight=rootToNodePath(root->right,n,path);
    if(isLeft||isRight){
        return true;
    }
    path.pop_back();//means both isLeft and isRight don't have the value
    return false;
}

template<class T>
int LCA1(NODE<T>* root,T n1,T n2){//O(N) and O(N)
    vector<T>path1;
    vector<T>path2;

    rootToNodePath(root,n1,path1);
    rootToNodePath(root,n2,path2);
    int LCA1=-1;
    for(int i=0,j=0;i<path1.size()&& j<path2.size(); i++,j++){
        if(path1[i]!=path2[j]){
            break;
        }
        LCA1=path1[i];
    }
    return LCA1;
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

int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);

    cout<<"The closest ancestor is: "<<LCA1(root,4,5)<<endl;
    cout<<"The closest ancestor is: "<<LCA2(root,4,5)->data<<endl;
    return 0;
}