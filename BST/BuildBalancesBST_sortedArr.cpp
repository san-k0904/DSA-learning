#include<iostream>
#include<vector>
#include<queue>
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

void levelorder(NODE* root){
    if(root==NULL){
        return;
    }
    queue<NODE*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        NODE* curr=q.front();
        q.pop();
        if(curr==NULL && q.empty()){
            cout<<endl;
            break;
        }
        else if(curr==NULL){
            cout<<endl;
            q.push(NULL);
        }
        else{
            cout<<curr->data<<"\t";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}
void Inorder(NODE* root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    Inorder(root->left,arr);
    arr.push_back(root->data);
    Inorder(root->right,arr);
}

NODE* BalancedBST(vector<int>arr,int st,int end){
    NODE* root;
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    root= new NODE(arr[mid]);
    root->left=BalancedBST(arr,st,mid-1);
    root->right=BalancedBST(arr,mid+1,end);
    return root;
}
int main(){
    vector<int>arr2={6,5,4,3,7,8,9};
    NODE* root=createBST(arr2,arr2.size());
    vector<int> arr;
    Inorder(root,arr);
    root=BalancedBST(arr,0,arr.size()-1);
    levelorder(root);
    cout<<endl;
    return 0;
}