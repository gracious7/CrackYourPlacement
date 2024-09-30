/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void fxn(Node* root, vector<int>& ans){
        if(root == NULL) return ;

        vector<Node*>child;
        child = root->children;

       ans.push_back(root->val);
       for(int i = 0; i< child.size(); i++){
            fxn(child[i], ans);

       }




    }



    vector<int> preorder(Node* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        
        fxn(root, ans);
        return ans;
    }
};