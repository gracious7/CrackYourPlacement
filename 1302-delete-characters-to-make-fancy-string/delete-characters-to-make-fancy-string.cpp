class Solution {
public:
    string makeFancyString(string s) {
        int n= s.size();
        if(n == 0 || n == 1) return s;
        string ans = "";
        ans += s[0];
        for(int i = 1; i<n-1; i++){
            if(!(s[i-1] == s[i] and s[i] == s[i+1])){
                ans += s[i];
            }
        }
        ans += s[n-1];
        return ans;
    }
};