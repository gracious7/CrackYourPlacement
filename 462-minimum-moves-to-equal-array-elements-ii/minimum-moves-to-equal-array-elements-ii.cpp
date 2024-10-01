class Solution {
public:

    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = (n-1)/2;
        int tmp = nums[k];
        int ans = 0;
        for(auto x: nums) ans += abs(tmp-x);
        return ans;

    }
};