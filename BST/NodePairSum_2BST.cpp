#include<iostream>
#include<vector>
#include<map>
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

NODE* createBST(vector<int>m, int n){
    NODE* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,m[i]);
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

void Find_2_Nodes_Sum(NODE* root1,NODE* root2,int target,map<int,int>& m){
    if(root1==NULL || root2==NULL){
        return;
    }
    int sum=root1->data+root2->data;
    if(sum<target){
        //first iterate through root2;
        Find_2_Nodes_Sum(root1,root2->right,target,m);
        //Now through root1;
        Find_2_Nodes_Sum(root1->right,root2,target,m);
    }
    else if(sum>target){
        //first iterate through root2;
        Find_2_Nodes_Sum(root1,root2->left,target,m);
        //Now through root1;
        Find_2_Nodes_Sum(root1->left,root2,target,m);
    }
    else{
        if(m.count(root1->data)==0){//put it in map so that data doesn't repeat...actually this is if is not req
        //coz anyways value will be same so m[root1->data]=root2->data will simply be same
            m[root1->data]=root2->data;
        }
    }

}
int main(){
    vector<int>arr1={5,3,2,4,7,6,8};
    NODE* root1=createBST(arr1,arr1.size());
    vector<int>arr2={10,6,3,8,15,11,18};
    NODE* root2=createBST(arr2,arr2.size());
    map<int,int>m;
