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

    int diam = 0;

    int mxh(TreeNode* root){
        if(root == NULL) return 0;

        int l = mxh(root->left);
        int r = mxh(root->right);
        
        
        diam = max(diam, l+r);

        return 1 + max(l, r);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return  0;

        mxh(root);

        return diam;
    }
};