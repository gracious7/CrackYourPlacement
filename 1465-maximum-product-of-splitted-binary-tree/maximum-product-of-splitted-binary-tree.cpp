class Solution {
public:
    long long ans = 0;   // 🔴 must be long long
    long long sum = 0;
    int mod = 1e9 + 7;

    long long f(TreeNode* root, int tot){
        if(root == NULL) return 0;

        long long left = f(root->left, tot);
        long long right = f(root->right, tot);

        long long subSum = left + right + root->val;
        ans = max(ans, subSum * (sum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        f(root, 0);
        return ans % mod;
    }
};
