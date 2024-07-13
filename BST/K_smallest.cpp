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
class Solution {
public:
     //1 way: use vectors and inorder traverse
    //2nd way:
    int kthSmallest(TreeNode* root, int& k){//& to pass by ref is imp
        if(root==NULL){
            return -1 ;//random value
        }
        
        int left=kthSmallest(root->left,k);

        k--;//backtrack and decrease... even if later root->right is called...till the time that has a left subtree
        //it's left subtree will be visited first coz it will be smaller and accordingly that will decrease k value first

        if(k==0){
            return root->val;
        }
        int right=kthSmallest(root->right,k);
        if(left==-1){
            return right;
        }
        else {
            return left;    
        }
    }
};