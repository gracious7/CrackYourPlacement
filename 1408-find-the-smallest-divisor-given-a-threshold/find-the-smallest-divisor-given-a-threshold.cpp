class Solution {
public:
    bool f(vector<int>&a, int th, int d){
        int c =0;
        for(auto x: a){
            c += ceil(x/(double)d);
        }
        if(c > th) return false;
        return true;
    }

    int smallestDivisor(vector<int>& nums, int th) {
        int s = 1, e = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(f(nums, th, m) == true){
                ans = m;
                e = m-1;
            }
            else s = m+1;
        }

        return s;

    }
};