class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = 0;
        for(auto x: words){
            if(x.substr(0, pref.size()) == pref) n++;
        }

        return n;
    }
};