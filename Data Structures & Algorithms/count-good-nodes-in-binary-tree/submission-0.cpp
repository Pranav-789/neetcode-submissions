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
    int traversal(TreeNode* root, int nmx){
        if(root == NULL) return 0;

        int ans = 0;
        if(root->val >= nmx) ans = 1; 

        ans += traversal(root->left, max(nmx, root->val));
        ans += traversal(root->right, max(nmx, root->val));
        return ans;
    }   
public:
    int goodNodes(TreeNode* root) {
        return traversal(root, -1e9);
    }
};
