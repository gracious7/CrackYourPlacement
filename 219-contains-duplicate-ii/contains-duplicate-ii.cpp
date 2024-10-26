class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i =0, j  =0;
        unordered_map<int, int>vis;
        int n = nums.size();
        if(k >= n) k = n-1;
        for(j = 0;j<=k; j++){
            if(vis.find(nums[j]) == vis.end()){
                vis[nums[j]]++;
            }
            else return true;
        }
        
        for(j = k+1; j<n; j++){
            vis.erase(nums[i]);
            if(vis.find(nums[j]) == vis.end()){
                vis[nums[j]]++;
            }
            else return true;
            i++;
        }

        return false;
    }
};