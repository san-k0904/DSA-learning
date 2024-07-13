#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Info{
public:
    bool isBst;
    int min;
    int max;
    int sum;
    Info(bool isBst,int min,int max,int sum){
        this->isBst=isBst;
        this->min=min;
        this->max=max;
        this->sum=sum;
    }
 };
class Solution {
public:
    int maxSum=0;//coz if sum is -ve we just ignore it
    Info* LargestSumBST(TreeNode* root){
        if(root==NULL){
            return new Info(true,INT_MAX,INT_MIN,0);
        }
        Info* leftInfo=LargestSumBST(root->left);
        Info* rightInfo=LargestSumBST(root->right);
        int currmin=min(root->val,min(leftInfo->min,rightInfo->min));
        int currmax=max(root->val,max(leftInfo->max,rightInfo->max));
        int currSum=leftInfo->sum + rightInfo->sum + root->val;
        //don't need to check for case when currSum<0 coz maxSum will still be 0
        if(leftInfo->isBst && rightInfo->isBst 
            && root->val < rightInfo->min
            && root->val > leftInfo->max){
            maxSum=max(maxSum,currSum);
            return new Info(true,currmin,currmax,currSum);
        }
        else{
            return new Info(false,currmin,currmax,currSum);
        }
    }
    int maxSumBST(TreeNode* root) {
        LargestSumBST(root);
        return maxSum;
    }
};