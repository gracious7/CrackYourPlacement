class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int>m;
        int nn = nums.size();
        int n = nn/2;
        for(auto x: nums){
            m[x]++;
            if(m[x] == n) return x;
        }
        return -1;
    }
};