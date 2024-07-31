// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

class Solution {
public:
    bool f(int ind, int n, vector<int>&a, vector<int>&dp){
        if(ind == n-1) return true;

        if(dp[ind] != -1) return dp[ind];
        bool p = false, np = false;
        for(int i = 1; i<= a[ind]; i++){
            if(f(ind+i, n, a, dp)) return dp[ind] = true;
        }
        return dp[ind] = false;

    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return f(0, nums.size(), nums, dp);
    }
};