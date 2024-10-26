class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string, int>m;
        int n = s.size();
        for(int i = 0;i<n; i++){
            if(i+10 <= n){
                m[s.substr(i, 10)]++;
            }
        }
        for(auto [el, val]: m){
            if(val > 1){
                ans.push_back(el);
            }
        }
        return ans;
    }
};