class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long cnt10 = 0, cnt01 = 0;
        int n = s.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && t[i] == '0') cnt10++;
            else if (s[i] == '0' && t[i] == '1') cnt01++;
        }

        if (2LL * flipCost < swapCost) {
            ans += (cnt10 + cnt01) * 1LL * flipCost;
            return ans;
        }

        long long a = min(cnt10, cnt01);
        long long b = max(cnt10, cnt01);

        ans += 1LL * swapCost * a;
        long long rem = b - a;

        if (2LL * flipCost > 1LL * swapCost + crossCost) {
            ans += (rem / 2) * (1LL * swapCost + crossCost);
            rem %= 2;
            ans += rem * 1LL * flipCost;
        } else {
            ans += rem * 1LL * flipCost;
        }

        return ans;
    }
};
