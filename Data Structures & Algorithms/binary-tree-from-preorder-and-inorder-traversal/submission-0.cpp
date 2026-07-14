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
    TreeNode* build(vector<int>& preorder, int pl, int ph,
                    vector<int>& inorder, int il, int ih,
                    unordered_map<int, int>& inorder_map) {

        if (pl > ph || il > ih)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[pl]);

        int index = inorder_map[preorder[pl]];
        int leftSize = index - il;

        root->left = build(preorder,
                           pl + 1,
                           pl + leftSize,
                           inorder,
                           il,
                           index - 1,
                           inorder_map);

        root->right = build(preorder,
                            pl + leftSize + 1,
                            ph,
                            inorder,
                            index + 1,
                            ih,
                            inorder_map);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;

        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        return build(preorder,
                     0,
                     preorder.size() - 1,
                     inorder,
                     0,
                     inorder.size() - 1,
                     inorder_map);
    }
};
