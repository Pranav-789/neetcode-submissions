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
        vector<vector<int>> ans;
        vector<int> level;

        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            if(it){
                level.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                if(q.front() == NULL){
                    q.push(NULL);
                }
            }else{
                if(level.size() > 0) ans.push_back(level);
                level.clear();
            }
        }
        return ans;
    }
};
