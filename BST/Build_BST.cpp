#include<iostream>
#include<vector>
using namespace std;

class NODE{
public:
    int data;
    NODE* left;
    NODE* right;

    NODE(int data){
        this->data=data;
        left=right=NULL;
    }

};
NODE* insert(NODE* root, int val){//O(logn)
    if(root==NULL){
        root=new NODE(val);
        return root;
    }

    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;

}

NODE* createBST(vector<int>arr, int n){
    NODE* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}

void Inorder(NODE* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<"\t";
    Inorder(root->right);
}

bool search(NODE* root, int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
NODE* getInorderSuccessor(NODE* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

NODE* deleteNode(NODE*root, int val){
    if(root==NULL){
        return NULL;
    }
    //first find the node
    if(val<root->data){
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteNode(root->right,val);
    }
    else{
        //3 cases

        //case1: 0 child
        if(!root->left && !root->right){
            delete(root);
            return NULL;
        }
        //case 2: 1 child
        else if(!root->left||!root->right){
            return root->left==NULL? root->right: root->right;
        }
        //case 3: 2 children
        else{
            NODE* inorderSucc= getInorderSuccessor(root->right);//bcoz successor is leftmost of right subtree
            root->data=inorderSucc->data;//change the data for node to delete and delete the succ. somewhere on the right
            root->right=deleteNode(root->right,inorderSucc->data);//only 2 cases is possible with succ. 0 child or 1 child
        }
    }
    return root;
}
int main(){
    vector<int>arr1={5,1,3,4,2,7};
    vector<int>arr2={8,5,3,1,4,6,10,11,14};
    NODE* root=createBST(arr2,arr2.size());
    Inorder(root);
    cout<<endl;
    cout<<(boolalpha)<<search(root,4)<<"\n";
    deleteNode(root,5);
    Inorder(root);
    return 0;
}