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

    bool inorder(TreeNode* p, TreeNode* q){
        // if(p == NULL || q == NULL) return p == q;
        if(p == NULL and q != NULL) return false;
        if(p != NULL and q == NULL) return false;
        if(p == NULL and q == NULL) return true;

        if(p->val != q->val) return false;

        bool l = inorder(p->left, q->left);
        bool r = inorder(p->right, q->right);


        return l and r;// dono me se koi ek v false return kiya then return false
    
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q != NULL) return false;
        if(p != NULL and q == NULL) return false;
        if(p == NULL and q == NULL) return true;

        return inorder(p, q);

    }
};