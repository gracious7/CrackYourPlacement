class Solution {
public:
    bool take(string& s) {
        if (s.size() == 0) return false;
        int n = s.size();
        n--;
        int cnt = 0;
        if (s[0] == 'a' || s[0] == 'e' || s[0] == 'o' || s[0] == 'i' || s[0] == 'u') cnt++;
        if (s[n] == 'a' || s[n] == 'e' || s[n] == 'o' || s[n] == 'i' || s[n] == 'u') cnt++;

        return cnt == 2;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> val;
        for (auto x : words) {
            if (take(x)) val.push_back(1);
            else val.push_back(0);
        }

        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + val[i - 1];
        }

        vector<int> ans;
        for (auto& q : queries) {
            int li = q[0], ri = q[1];
            ans.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }

        return ans;
    }
};
