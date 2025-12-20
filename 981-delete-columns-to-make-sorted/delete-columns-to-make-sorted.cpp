class Solution {
public:
    bool isSorted(string s){
        string ss = s;
        sort(ss.begin(), ss.end());
        return s == ss;

    }
    int minDeletionSize(vector<string>& strs) {
        int ans= 0;
        int n = strs.size();
        int nn =strs[0].size();
        vector<string> st(nn);
        for(int j = 0; j<nn; j++){
            string s = "";
            for(int i = 0; i < n; i++){
                s = s + strs[i][j];
            }
            if(!isSorted(s)) ans++;
        }
        return ans;
    }
};