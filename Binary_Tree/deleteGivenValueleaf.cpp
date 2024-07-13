#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL){
            return NULL;
        }
        root->left= removeLeafNodes(root->left,target);
        root->right= removeLeafNodes(root->right,target);
        if(root->left==NULL && root->right==NULL){
            if(root->val==target){
                root=NULL;
                delete root;
            }
        }
        return root;
    }
};