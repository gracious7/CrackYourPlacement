class Solution {
public:

    void func(int i, int n, vector<int>ds, vector<vector<int>>&ans, vector<int>&nums){
        if(i == n){
            ans.push_back(ds);
            return;
        }        

        //np 
        func(i+1, n, ds, ans, nums);

        // pick
        ds.push_back(nums[i]);
        func(i+1, n, ds, ans, nums);


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>ds;
        vector<vector<int>>ans;

        func(0, n, ds, ans, nums);

        return ans;
    }
};