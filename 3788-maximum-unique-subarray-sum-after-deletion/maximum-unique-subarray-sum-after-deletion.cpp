class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        for(auto x: nums)s.insert(x);
        int mx = INT_MIN;
        int ans =0;
        bool f = false;
        for(auto x: s){
            mx = max(mx, x);
            if(x > 0){
                ans += x;
                f = true;
            }
        }

        if(f == false){
            return mx;
        }
        return ans;
    }
};