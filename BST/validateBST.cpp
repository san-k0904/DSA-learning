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
bool validateHelper(NODE* root,NODE* min,NODE* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    return validateHelper(root->left,min,root)
        && validateHelper(root->right,root,max);
}
bool validate(NODE* root){
    return validateHelper(root,NULL,NULL);
}
int main(){
    vector<int>arr1={5,1,3,4,2,7};
    vector<int>arr2={8,5,3,1,4,6,10,11,14};
    NODE* root=createBST(arr2,arr2.size());
    Inorder(root);
    cout<<endl;
    cout<<boolalpha<<validate(root);
    cout<<endl;
    return 0;
}