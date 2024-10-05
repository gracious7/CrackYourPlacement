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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return  ans;

        queue<TreeNode*>q;
        q.push(root);
        bool l = true;
        while(!q.empty()){
            int s = q.size();
            vector<int>ds;
            for(int i = 0; i<s; i++){
                TreeNode* top = q.front();
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
                ds.push_back(top->val);
            }
            if(l){
                ans.push_back(ds);
                l = !l;
            }
            else {
                reverse(ds.begin(), ds.end());
                ans.push_back(ds);
                l = !l;
            }

        }
        return ans;
    }
};