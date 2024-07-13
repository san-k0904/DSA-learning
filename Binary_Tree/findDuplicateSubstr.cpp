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
class Solution {
public:
    string duplicate(TreeNode* root, vector<TreeNode*>& v,map<string,int>& m){
        if(root==NULL){
            return "";
        }
        string a= duplicate(root->left,v,m);
        string b= duplicate(root->right,v,m);
        string temp= to_string(root->val)+" , "+a+" , "+b;
        m[temp]++;
        if(m[temp]==2){
            v.push_back(root);
        }
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int> m;//tree and it's freq;
        vector<TreeNode*> v;
        duplicate(root,v,m);
        return v;
    }
};