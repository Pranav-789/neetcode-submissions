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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(!p ||!q) return false;

        bool ans1 = isSameTree(p->left, q->left);
        bool ans2 = isSameTree(p->right, q->right);

        bool ans3 = p->val == q->val;

        return ans1 && ans2 && ans3;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;

        if(!root ||!subRoot) return false;

        bool ans = isSameTree(root, subRoot);
        bool ans1 = isSubtree(root->left, subRoot);
        bool ans2 = isSubtree(root->right, subRoot);

        return ans1 || ans2 || ans;
    }
};
