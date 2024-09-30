class Solution {
public:
    int findContentChildren(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        int i =0, j = 0, m= p.size(), n = t.size();
        int ans = 0;
        while(i <m and j < n){
            if(p[i] > t[n-1]) break;
            if(p[i] <= t[j] ){
                i++;
                j++;
                ans++;
            }
            else j++;
        }
        return ans;
    }
};