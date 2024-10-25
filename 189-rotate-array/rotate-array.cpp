class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k = k%n;
        vector<int>v;
        for(int i = 0; i<k; i++){
            v.push_back(nums[n-k+i]);
        }
        for(int i = 0;i<n-k; i++){
            v.push_back(nums[i]);
        }
        nums = v;
    }
};