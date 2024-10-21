class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int n = s.size();
        
        int i = 0, j =0;
        vector<int>v(26, 0);
        int mx = 0;
        while(j < n){
            v[s[j]-'a']++;
            while(i < n and v[s[j]-'a'] == k){
                ans += n-j;
                v[s[i]-'a']--;
                i++;
            }
            j++;
        }

        return ans;
    }
};