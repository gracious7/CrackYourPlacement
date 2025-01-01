class Solution {
public:
    int maxScore(string s) {
        int to = 0;
        int ans = 0, cur = 0;
        int n = s.size();
        for(auto x: s)if(x == '1') to++;
        // if(s[0] == '1')cur++;
        for(int i = 0; i<s.size()-1; i++){
            if(s[i] == '1'){
                cur++;
            } 
            ans = max(ans, to-cur + i+1-cur);
        }
        return ans;
    }
};