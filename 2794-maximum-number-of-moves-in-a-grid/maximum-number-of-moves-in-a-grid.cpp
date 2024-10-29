class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int p1 = 0, p2 = 0, p3 = 0;
                if (i > 0 && grid[i][j] < grid[i - 1][j + 1]) {
                    p1 = 1 + dp[i - 1][j + 1];
                } 
                if (i < n - 1 && grid[i][j] < grid[i + 1][j + 1]) {
                    p2 = 1 + dp[i + 1][j + 1];
                }
                if (grid[i][j] < grid[i][j + 1]) {
                    p3 = 1 + dp[i][j + 1];
                }
                dp[i][j] = max({p1, p2, p3});
                if(j==0)
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};