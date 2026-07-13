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

        // if(ans.size() < height){
        //     ans.push_back(root->val);
        // }else 
        ans[height] = root->val;

        traverse(root->left, height+1, ans);
        traverse(root->right, height+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> atHeight(100, -1);
        vector<int> ans;

        traverse(root, 0, atHeight);
        for(int i = 0; i < 100; i++){
            if(atHeight[i] == -1) break;
            ans.push_back(atHeight[i]);
        }
        return ans;
    }
};
