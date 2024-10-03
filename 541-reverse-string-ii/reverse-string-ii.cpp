class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        if(k == 1) return s;
        if(n <= k){
            reverse(s.begin(), s.end());
            return s;
        }
        if(n <= 2*k) {
            string ss = s.substr(0, k);
            reverse(ss.begin(), ss.end());
            ss += s.substr(k);
            return ss;
        }
        string ans = "";
        for(int i = 0; i<n; i+= 2*k){
            string ss ;
            if(i+k > n){
                ss = s.substr(i);
                reverse(ss.begin(), ss.end());
                ans += ss;
            }
            else if(i+k+k > n){
                ss = s.substr(i, k);
                reverse(ss.begin(), ss.end());
                ans += ss;
                ans += s.substr(i+k);

            }
            else {
                ss = s.substr(i, k);
                reverse(ss.begin(), ss.end());
                ans += ss;
                ans += s.substr(i+k, k);
                
            }
        }
        return ans;
    }
};