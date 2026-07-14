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
    TreeNode* build(
        vector<int>& preorder, int pleft, int pright,
        vector<int>& inorder, int ileft, int iright,
        unordered_map<int, int>& mp
    ){
        if(pleft > pright || ileft > iright) return NULL;

        TreeNode* root = new TreeNode(preorder[pleft]);

        int index = mp[preorder[pleft]];

        root->left = build(
            preorder, pleft+1, pleft + index-ileft,
            inorder, ileft, index-1,
            mp
        );

        root->right = build(
            preorder, pleft + index -ileft + 1, pright,
            inorder, index+1, iright,
            mp
        );

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)mp[inorder[i]] = i;
        return build(
            preorder, 0, n-1,
            inorder, 0, n-1, mp
        );
    }
};
