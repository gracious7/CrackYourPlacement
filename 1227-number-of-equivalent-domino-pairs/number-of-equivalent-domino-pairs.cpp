struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};
class Solution {
public:
    
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(), dominoes.end());
        int ans =0;
        int n= dominoes.size();
        unordered_map< pair<int, int>, int, PairHash> m;
        for(int i = 0; i<n; i++){
            sort(dominoes[i].begin(), dominoes[i].end());
            m[{dominoes[i][0], dominoes[i][1]}]++;
        }
        for(auto x: m){
            ans += (x.second * (x.second - 1)) / 2;
        }
        
        return ans;
    }
};