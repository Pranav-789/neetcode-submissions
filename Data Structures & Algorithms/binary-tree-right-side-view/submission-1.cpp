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
    void traverse(TreeNode* root, int height, vector<int>& ans){
        if(root == NULL) return;

        if (height == ans.size()) ans.push_back(root->val);

        traverse(root->right, height+1, ans);
        traverse(root->left, height+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> atHeight;

        traverse(root, 0, atHeight);
        return atHeight;
    }
};
