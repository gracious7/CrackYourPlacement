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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        // if(root->left == NULL and root->right == NULL) {
        //     if(key = root->val) return NULL;
        //     return root;
        // }

        TreeNode* head = root;
        TreeNode* prev = root;
        bool rt = false;

        while(head != NULL){
            
            if(key == head->val){
                if(prev->right == head) rt = true;
                TreeNode* l = head->left;
                TreeNode* r = head->right;
                TreeNode* nhead = head->right;
                if(nhead == NULL){
                    if(head == root){
                        return l;
                    }
                    if(rt == true) prev->right = l;
                    else prev->left = l;
                    return root;
                }
                
                while(nhead->left != NULL ){
                    nhead = nhead->left;
                }
                if(nhead != NULL) nhead->left = l;

                if(head == root){
                    return head->right;
                }
                if(rt == true){
                    prev->right = r;
                }
                else prev->left = r;
                return root;

            }

            prev = head;
            if(key > head->val) head = head->right;
            else head = head->left;

        }


        return root;
    }
};