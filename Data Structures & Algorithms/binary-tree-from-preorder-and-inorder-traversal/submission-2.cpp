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
        vector<int>& inorder, int ileft, int iright
    ){
        if(pleft > pright || ileft > iright) return NULL;

        TreeNode* root = new TreeNode(preorder[pleft]);

        int index = 0;
        for(int i = ileft; i <= iright; i++){
            if(inorder[i] == preorder[pleft]){
                index = i;
                break;
            }
        }

        root->left = build(
            preorder, pleft+1, pleft + index-ileft,
            inorder, ileft, index-1
        );

        root->right = build(
            preorder, pleft + index -ileft + 1, pright,
            inorder, index+1, iright
        );

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(
            preorder, 0, preorder.size()-1,
            inorder, 0, inorder.size() - 1
        );
    }
};
