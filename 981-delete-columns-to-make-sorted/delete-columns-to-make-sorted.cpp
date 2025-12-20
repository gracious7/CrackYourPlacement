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
        for(int j = 0; j<nn; j++){
            bool f = false;
            for(int i =1; i<n; i++){
                if(strs[i][j] < strs[i-1][j]) {
                    f = true;
                }

            }
            if(f == true) ans++;
        }
        return ans;
    }
};