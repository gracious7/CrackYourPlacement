class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;

        int maxStreak = 1;
        
        for (int num : nums) {
            int root = sqrt(num);
            if (root * root == num && dp.count(root)) {
                dp[num] = dp[root] + 1;
            } else {
                dp[num] = 1;
            }
            maxStreak = max(maxStreak, dp[num]);
        }
        
        return maxStreak >= 2 ? maxStreak : -1;
    }
};