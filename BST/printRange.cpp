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

void print_in_Range(NODE*root, int start,int end){
    if(root==NULL){
        return;
    }
    if(start<=root->data && root->data<=end){
        print_in_Range(root->left,start,end);
        cout<<root->data<<" ";//backtracking like this so that value is inorder format...i.e sorted
        print_in_Range(root->right,start,end);
    }
    else if(root->data<start){//in case say our start is 4 we are on 5 and to left is 3 but to it's right is 4
        print_in_Range(root->right,start,end);
    }
    else if(root->data>end){
        print_in_Range(root->left,start,end);
    }
}
int main(){
    vector<int>arr1={5,1,3,4,2,7};
    vector<int>arr2={8,5,3,1,4,6,10,11,14};
    NODE* root=createBST(arr2,arr2.size());
    Inorder(root);
    cout<<endl;
    print_in_Range(root,5,12);
    cout<<endl;
    return 0;
}