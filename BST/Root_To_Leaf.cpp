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

void RootToLeaf(NODE* root,vector<int> path){//if i am passing by ref. then pop_back
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        for(auto i:path){
            cout<<i<<"\t";
        }
        cout<<"\n";
        // path.pop_back();
        return;
    }
        
    RootToLeaf(root->left,path);
    RootToLeaf(root->right,path);
    // path.pop_back();// if vector was not passed by ref then pop_back wasn't required
}

int main(){
    vector<int>arr1={5,1,3,4,2,7};
    vector<int>arr2={8,5,3,1,4,6,10,11,14};
    NODE* root=createBST(arr2,arr2.size());
    Inorder(root);
    cout<<endl;
    vector<int>path;
    RootToLeaf(root,path);
    return 0;
}