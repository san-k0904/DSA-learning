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
class Info{
    public:
        bool isBst;
        int min;
        int max;
        int size;

        Info(bool isBst, int min,int max,int size){
            this->isBst=isBst;
            this->min=min;
            this->max=max;
            this->size=size;
        }
};

static int maxSize=INT_MIN;

Info* FindLargestBST(NODE* root){
    //BASE CASE 1
    if(root==NULL){
        return new Info(true,INT_MAX,INT_MIN,0);//min=INT_MAX coz root-<data < min of right to be BST
        //similarly max=INT_MIN coz we compare root->data > max of left
    }

    //BASE CASE 2
    // if(root==NULL){
    //     return NULL;
    // }
    // if(root->left==NULL && root->right==NULL){
    //     return new Info(true,root->data,root->data,1);
    // }
    Info* leftInfo=FindLargestBST(root->left);
    Info* rightInfo=FindLargestBST(root->right);

    int currMin=min(root->data,min(leftInfo->min,rightInfo->min));
    int currMax=max(root->data,max(leftInfo->max,rightInfo->max));
    int currsize= leftInfo->size+rightInfo->size+1;
    if(leftInfo->isBst && rightInfo->isBst 
        && root->data > leftInfo->max 
        && root->data < rightInfo->min){
            maxSize=max(maxSize,currsize);
            return new Info(true,currMin,currMax,currsize);
        }
    else{
        return new Info(false,currMin,currMax,currsize);
    }
}
int main(){
    NODE* root= new NODE(50);
    root->left=new NODE(30);
    root->left->left=new NODE(5);
    root->left->right=new NODE(30);
    root->right=new NODE(60);
    root->right->left=new NODE(45);
    root->right->right=new NODE(70);
    root->right->right->left=new NODE(65);
    root->right->right->right=new NODE(80);

    FindLargestBST(root);
    cout<<"Max size : "<<maxSize<<endl;
    re