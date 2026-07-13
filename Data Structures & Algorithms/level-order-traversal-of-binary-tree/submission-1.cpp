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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;

        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            vector<int> level;
            while(sz--){
                auto it = q.front();
                q.pop();

                level.push_back(it->val);

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
