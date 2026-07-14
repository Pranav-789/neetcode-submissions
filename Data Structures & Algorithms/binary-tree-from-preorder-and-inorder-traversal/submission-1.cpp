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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);

        int index = 0;
        for(int i = 0; i < n; i++){
            if(inorder[i] == preorder[0]){
                index = i;
                break;
            }
        }

        int pre_size = index;
        int post_size = n - index - 1;

        vector<int> preleft;
        for(int i = 1; i < 1 + pre_size; i++){
            preleft.push_back(preorder[i]);
        }

        vector<int> preright;
        for(int i = 1 + pre_size; i < n; i++){
            preright.push_back(preorder[i]);
        }

        vector<int> inleft;
        for(int i = 0; i < index; i++){
            inleft.push_back(inorder[i]);
        }

        vector<int> inright;
        for(int i = index+1; i < n; i++){
            inright.push_back(inorder[i]);
        }

        root->left = buildTree(preleft, inleft);
        root->right = buildTree(preright, inright);

        return root;
    }
};
