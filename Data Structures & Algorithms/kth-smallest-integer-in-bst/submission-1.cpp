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
    void ans(TreeNode* root, int& k, int& res){
        if(root == NULL) return;

        ans(root->left, k, res);
        if(k > 0){
            k--;
        }if(k == 0){
            k--;
            res = root->val;
            return;
        }

        ans(root->right, k, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        ans(root, k, res);
        return res;
    }
};
