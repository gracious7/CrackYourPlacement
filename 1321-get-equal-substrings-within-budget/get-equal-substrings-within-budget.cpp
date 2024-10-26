class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>v;
        int n = s.size();
        for(int i =0;i<n; i++){
            int a = s[i]-'a';
            int b = t[i]-'a';
            v.push_back(abs(a-b));
        }
        
        int i =0, j = 0;
        int ans = 0, sum = 0;
        while(j<n){
            sum += v[j];
            while(i<n and sum > maxCost){
                sum -= v[i];
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;

    }
};