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
        vector<vector<int>>ans;

        if(root == NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            //sabse pehle check krenge ki current level me kitne node h
            int sz = q.size();// ye current level k number of nodes
            
            //hr level k liye ek vector banayenge
            vector<int>level;

            for(int i = 0; i<sz;i++){
                TreeNode* tp = q.front();
                q.pop();
                
                //store/print
                cout<<tp->val;
                level.push_back(tp->val);


                //jaise jaise node bahar nikalenge waise waise uske childs ko push kre denge
                if(tp->left != NULL) q.push(tp->left);
                if(tp->right) q.push(tp->right);

            }

            ans.push_back(level);


        }


        return ans;


    }
};