class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;

        int i =0, j = 0;
        int sum =0;
        while(j< n){
            sum += nums[j];
            while(i <= j and sum >= tar){
                ans = min(ans, j-i+1);
                sum -= nums[i++];
            }
            j++;

        }
        return ans == 1e9 ? 0 : ans;



    }
};