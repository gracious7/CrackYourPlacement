class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int cnt = 0;
        int n = s.size();
        for(int i= 0; i<s.size(); i++){
            vector<int>v(26, 0);
            for(int j = i; j<n; j++){
                v[s[j]-'a']++;
                if(v[s[j]-'a'] >= k) {
                    ans = ans + n-j;
                    break;
                }
            }

        }
        return ans;
    }
};