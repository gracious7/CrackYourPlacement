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
    void f(TreeNode* root, unordered_map<TreeNode*, int>&m){
        if(root==NULL) return ;
        int sum = 0;
        if(root->left){
            sum += root->left->val;
        }
        if(root->right){
            sum += root->right->val;
        }
        if(root->left){
            m[root->left] = sum;
            f(root->left, m);
        }
        if(root->right){
            m[root->right] = sum;
            f(root->right, m);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*, int>m;
        f(root, m);
        m[root] = root->val;
        // for(auto [el, val] : m){
        //     cout<<el->val<<" : "<<val<<endl;
        // }
        queue<TreeNode*> q;
        q.push(root);

        vector<int>level;
        int l = 0;

        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            for(int i = 0; i<sz; i++){
                auto tp = q.front();
                q.pop();
                sum += tp->val;

                if(tp->left)q.push(tp->left);
                if(tp->right)q.push(tp->right);
            }
            level.push_back(sum);
            // cout<<sum<<' ';
        }

        queue<TreeNode*>qq;
        qq.push(root);
        l = 0 ;
        while(!qq.empty()){
            int sz = qq.size();

            for(int i = 0; i<sz; i++){
                auto tp = qq.front();
                qq.pop();

                tp->val = level[l] - m[tp];

                if(tp->left)qq.push(tp->left);
                if(tp->right)qq.push(tp->right);
            }
            l++;

        }

        return root;

    }
};