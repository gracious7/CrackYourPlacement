class Solution {
public:
    string f(string s){
        // string s = to_string(n);
        int cnt = 1;
        string ans = "";
        int n = s.size();
        for(int i = 0; i<s.size(); ){
            int j = i+1;
            while(j<n and s[j] == s[j-1]){
                j++;
                cnt++;
            }
            ans += to_string(cnt) + s[i];
            i = j;
            cnt = 1;

        }

        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        
        if(n == 1) return ans;
        for(int i = 1; i<n; i++){
            ans = f(ans);
        }
        return ans;

    }
};