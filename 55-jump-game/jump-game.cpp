class Solution {
public:

    bool solve(int ind, int n, vector<int>&nums, vector<int>&dp){
        if(ind == n-1) return true;
        if(ind >= n) return false;
        if(dp[ind] != -1) return dp[ind];
        for(int i = 1; i<= nums[ind]; i++){
            if(ind+i == n-1) return true;
            if(ind+1 < n){

                if(solve(ind+i, n, nums, dp)) return dp[ind] = true;
            }
        }
        return dp[ind] = false;

    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int n = nums.size();
        vector<int>dp(n, -1);
        return solve(0, nums.size(), nums, dp);
    }
};