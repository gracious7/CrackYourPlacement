class Solution {
public:
    bool isIsomorphic(string t, string s) {
        if(s.size() != t.size()) return false;
        if(s == t) return true;
        
        unordered_map<char, char>m;
        unordered_map<char, char>mm;
        int n = s.size();
        for(int i = 0;i<n; i++){
            // if(s[i]= t[i]){
                if(m.find(s[i]) == m.end()){
                    m[s[i]] = t[i];
                }
                else{
                    if(m[s[i]] != t[i]) return false;
                }
            // }
        }

        for(int i = 0;i<n; i++){
            // if(s[i]= t[i]){
                if(mm.find(t[i]) == mm.end()){
                    mm[t[i]] = s[i];
                }
                else{
                    if(mm[t[i]] != s[i]) return false;
                }
            // }
        }
        return true;

    }
};