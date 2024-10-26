class Solution {
public:

    bool f(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        if(i == s.size() and j == p.size()) return true;

        if(i > s.size() || j >= p.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool a = false, b = false, c = false;

        if(s[i] == p[j]){
            a = f(i+1, j+1, s, p, dp);
        }
        else if(p[j] == '?'){
            a = f(i+1, j+1, s, p, dp);
        }
        else if(p[j] == '*'){
           a =  f(i+1, j, s, p, dp);
           b =  f(i+1, j+1, s, p, dp);
           c =  f(i, j+1, s, p, dp);
        }

        return dp[i][j] = a or b or c;


    }

    bool isMatch(string s, string p) {
        int m= s.size(), n = p.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return f(0, 0, s, p, dp);
    }
};