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
    int ans(TreeNode* root, int& k){
        if(root == NULL) return 0;

        int a = ans(root->left, k);
        if(k > 0){
            k--;
        }if(k == 0){
            k--;
            return root->val;
        }

        int b = ans(root->right, k);
        return a + b;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return ans(root, k);
    }
};
