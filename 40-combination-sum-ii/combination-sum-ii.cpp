class Solution {
public:

    void f(int ind, int n, int tar, vector<int>&cnd, vector<int>ds, vector<vector<int>>&ans){
        if(tar == 0){
            ans.push_back(ds);
            return;
        }
        if(ind >= n) return;

        for(int i = ind; i<n; i++){
            if(ind != i and cnd[i] == cnd[i-1]) continue;

            if(cnd[i] <= tar){
                ds.push_back(cnd[i]);
                f(i+1, n, tar-cnd[i], cnd, ds, ans);
                ds.pop_back();
            }

        }
        return;
        
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        int n = candidates.size();
        f(0, n, target, candidates, ds, ans);

        return ans;

        
    }
};