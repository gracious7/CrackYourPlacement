class Solution {
public:
    string reversePrefix(string s, int k) {
        string ss = s.substr(k);
        string rs = s.substr(0, k);
        cout<<rs<<endl;
        reverse(rs.begin(), rs.end());
        return rs+ss;
    }
};