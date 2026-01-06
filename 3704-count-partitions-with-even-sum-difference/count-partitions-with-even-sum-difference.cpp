class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int ans = 0;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i<n-1; i++){
            prev += nums[i];
            int x = prev, y = tot-prev;
            int diff = y-x;
            if(diff%2 == 0) ans++;
        }

        return ans;

    }
};