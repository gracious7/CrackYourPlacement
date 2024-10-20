class Solution {
public:
    void f(int i, int n,  vector<int>ds, vector<int>&nums, vector<vector<int>>&ans){
        if(i == n){
            ans.push_back(ds);
            return;
        }

        //np or not take
        f(i+1, n, ds, nums, ans);

        //p or pick
        ds.push_back(nums[i]);
        f(i+1, n, ds, nums, ans);

        return ;

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int i = 0;
        int n = nums.size();

        f(i, n, ds, nums, ans);

        return ans;

    }
};