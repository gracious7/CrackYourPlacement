class Solution {
public:

    void f(int i, int n, vector<int>&a, vector<int>ds, vector<vector<int>>&ans){
        if(i == n){
            ans.push_back(ds);
            return;
        }

        //not take
        f(i+1, n, a, ds, ans);//kuch nhi liye bs ek index badha diye

        //take
        ds.push_back(a[i]);
        f(i+1, n, a, ds, ans);//ds me lekr fir aage badhe

        return ;

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;

        int i = 0, n = nums.size();
        vector<int>ds;

        f(i, n, nums, ds, ans);

        return ans;

    }
};