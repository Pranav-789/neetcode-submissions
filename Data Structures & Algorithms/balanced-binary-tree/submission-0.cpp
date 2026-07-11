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
    int ans(TreeNode* root, bool& balanced){
        if(root == NULL) return 0;

        int l = ans(root->left, balanced);
        int r = ans(root->right, balanced);

        if(abs(l-r) > 1) balanced = false;

        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        ans(root, res);
        return res;
    }
};
