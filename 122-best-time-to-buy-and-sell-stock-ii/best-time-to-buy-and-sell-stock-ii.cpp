class Solution {
public:
    int f(int i, int bought, int n, vector<int>&price, vector<vector<int>>&dp){
        if(i == n) return 0;
        if(dp[i][bought] != -1) return dp[i][bought];
        int profit = 0;
        if(bought == 1){
            profit = max(-price[i] + f(i+1, 0, n, price, dp), f(i+1, 1, n, price, dp));

        }
        else{
            profit = max( price[i] + f(i+1, 1,  n, price, dp), f(i+1, 0, n, price, dp));
            
        }

        return dp[i][bought]= profit;
        

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return f(0, 1, n, prices, dp);
    }
};