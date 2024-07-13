#include<iostream>
#include<vector>
#include<numeric>
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
int minAbsoluteDiff=INT_MAX;

int FindMinAbsoluteDiff(NODE* root,int k){
    if(root==NULL){
        return 0;//doesn't matter what we return coz we are not using it
    }
    if(root->data < k){
        minAbsoluteDiff=min(minAbsoluteDiff,abs(k-root->data));
        FindMinAbsoluteDiff(root->right,k);
    }
    else if(root->data > k){
        minAbsoluteDiff=min(minAbsoluteDiff,abs(k-root->data));
        FindMinAbsoluteDiff(root->left,k);
    }
    if(root->data==k){
        minAbsoluteDiff=0;
        return minAbsoluteDiff;
    }
    return minAbsoluteDiff;
}

int main(){
    NODE* root= new NODE(8);
    root->left= new NODE(5);
    root->left->left= new NODE(3);
    root->left->right= new NODE(6);
    root->right= new NODE(11);
    root->right->right= new NODE(20);
    cout<<FindMinAbsoluteDiff(root,19)<<endl;
    return 0;
}