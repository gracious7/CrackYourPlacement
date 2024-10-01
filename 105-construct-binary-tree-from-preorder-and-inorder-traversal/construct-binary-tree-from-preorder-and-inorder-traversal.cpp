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

    TreeNode* f(vector<int>& p, vector<int>&ino, int i, int s, int e){
        if(i >= p.size()) return NULL;
        if(s >e) return NULL;
        TreeNode* root = new TreeNode(p[i]);

        int idx = -1;
        for(int k = s; k<=e; k++){
            if(ino[k] == p[i]){
                idx = k;
                break;
            }
        }

        root->left = f(p, ino, i+1, s, idx-1);
        root->right = f(p, ino, i+(idx-s+1), idx+1, e);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(preorder, inorder, 0, 0, inorder.size()-1);
    }
};