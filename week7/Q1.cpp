/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int level, vector<int>&result,unordered_set<int>&SET){
        if(root==NULL){
            return;
        }
        if(SET.find(level)==SET.end()){
            SET.insert(level);
            result.push_back(root->val);
        }
        helper(root->right,level+1,result,SET);
        helper(root->left,level+1,result,SET);
    }

    vector<int> rightSideView(TreeNode* root) {
        int level=1;
        vector<int>result;
        unordered_set<int>SET;
        helper(root,level,result,SET);
        return result;
    }
};
