class Solution {
public:

    int f(int ind, int n, vector<int>&nums, vector<int>&dp){
        if(ind == n-1) return 0;

        if(dp[ind] != -1) return dp[ind];
        int ans = n;
        for(int i = 1; i<=nums[ind]; i++){
            if(ind+i < n){
                int x = 1+f(ind+i, n, nums, dp);
                ans = min(x, ans);
            }
        }

        return dp[ind] = ans;


    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return f(0, n, nums, dp);

    }
};