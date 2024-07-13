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
void merge(vector<int>&arr1,vector<int>&arr2){
    int i=0;
    int j=0;
    vector<int> temp;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }
        else{
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()){
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()){
        temp.push_back(arr2[j]);
        j++;
    }
    // i=0;
    // while(i<temp.size()){
    //     arr1[i]=temp[i];
    //     i++;
    // }
    arr1=temp;
}
int main(){
    NODE* root1= new NODE(2);
    root1->left=new NODE(1);
    root1->right=new NODE(4);

    NODE* root2= new NODE(9);
    root2->left=new NODE(3);
    root2->right=new NODE(12);
    vector<int>arr1;
    vector<int>arr2;
    Inorder(root1,arr1);
    Inorder(root2,arr2);
    merge(arr1,arr2);
    NODE* root=BalancedBST(arr1,0,arr1.size()-1);
    levelorder(root);
    cout<<endl;
    return 0;
}