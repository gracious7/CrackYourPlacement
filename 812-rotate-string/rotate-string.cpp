class Solution {
public:
    bool rotateString(string s, string ss) {
        int n = s.size();
        int m = ss.size();
        if(n != m)return false;
        if(s == ss) return true;

        for(int i = 0; i<n; i++){
            string res = s.substr(i, n-i) + s.substr(0, i);
            if(res == ss) return true;
        }
        return false;
    }
};