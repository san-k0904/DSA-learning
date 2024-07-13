#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {//LEETCODE 124
public:
    int maxPathSumHelper(TreeNode* root,int& maxsum){
        if(root==NULL){
            return 0;
        }
        int lefthand= max(0,maxPathSumHelper(root->left,maxsum));
        int righthand= max(0,maxPathSumHelper(root->right,maxsum));

        maxsum=max(maxsum, lefthand+righthand+root->val);


        return max(lefthand,righthand)+root->val;//select the maximum hand

        //basically say you have 9+ (-10) you went down to 20 and now have to decide which hand...(acc.->LEETCODE 124 eg)
        //so you pick the max hand + node with 20 and return it above
    }
    int maxPathSum(TreeNode* root) {
        int max=INT_MIN;
        maxPathSumHelper(root,max);
        return max;
    }
};