class Solution {
public:
    int countHillValley(vector<int>& a) {
        int ans = 0;
        int an = a.size();
        vector<int>nums;
        nums.push_back(a[0]);
        for(int i =1; i<an; i++){
            if(a[i] != a[i-1]) nums.push_back(a[i]);
        }
        int n = nums.size();

        for(int i = 1; i<n-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) ans++;
            if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) ans++;
            
        }

        return ans;
    }
};