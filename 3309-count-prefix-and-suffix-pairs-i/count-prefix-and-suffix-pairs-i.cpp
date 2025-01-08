class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& w) {
        int n = w.size();
        int ans = 0;
        for(int i =0; i<n;i++){
            for(int j = i+1; j<n; j++){
                int a = w[i].size();
                if (w[j].substr(0, a) == w[i] && w[j].substr(w[j].size() - a) == w[i]) ans++;
            }
        }
        return ans;
    }
};