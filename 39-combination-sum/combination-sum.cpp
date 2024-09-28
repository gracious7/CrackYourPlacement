class Solution {
public:

    void csm(int i, int n, vector<int>&cnd, int tar,vector<int>ds, vector<vector<int>>&ans){
        if(tar<0) return;
        if(i == n){
            if(tar == 0){
                ans.push_back(ds);
            }
            return;
        }
        // if(tar == 0){
        //     ans.push_back(ds);
        //     // return;
        // }
        if(cnd[i] <= tar){
            ds.push_back(cnd[i]);
            csm(i, n, cnd, tar-cnd[i], ds, ans);
            ds.pop_back();
        }
        csm(i+1, n, cnd, tar, ds, ans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        csm(0, candidates.size(), candidates, target, ds, ans);
        return ans;
    }
};