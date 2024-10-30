class Solution {
public:
    int f(int i, int n,  vector<int>&nums, vector<int>&dp){
        // if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int mx = 1;
        for(int j = 0; j<i; j++){
            if(nums[j] < nums[i]){
                mx = max(mx, 1+f(j, n, nums, dp));
            }
        }

        return dp[i] =  mx;

    }
    int frl(int i, int n, vector<int>& nums, vector<int>& dp) {
        if(dp[i] != -1) return dp[i];

        int mx = 1;
        for(int j = i+1; j<n; j++){
            if(nums[j] < nums[i]){
                mx = max(mx, 1+frl(j, n, nums, dp));
            }
        }

        return dp[i] = mx;
    }


    int minimumMountainRemovals(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n, -1);
        vector<int>dp2(n, -1);

        vector<int>l(n);
        vector<int>r(n);

        for(int i =0; i<n; i++){
            l[i] = f(i, n, nums, dp);
        }
        for(int i =0; i<n; i++){
            r[i] = frl(i, n, nums, dp2);
        }
        int mx = INT_MIN ;
        int ind = -1;
         for (int i = 1; i < n - 1; i++) {
            if (l[i] > 1 && r[i] > 1) {
                mx = max(mx, l[i] + r[i] - 1);  
            }
        }

        return n -mx;


    }
};