class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>f(26, 0);
        vector<int>window(26, 0);
        for(auto x: s1) f[x-'a']++;

        int l = s1.size();
        int n = s2.size();
        if(l > n)  return false;

        for(int i = 0; i<l; i++){
            window[s2[i]-'a']++;
        }
        if(f == window) return true;

        int i = 0, j = l;
        while( i<n and j < n and i <= j){
            window[s2[j]-'a']++;
            window[s2[i]-'a']--;
            if(window == f) return true;
            i++;
            j++;
        }
        return false;


    }
};