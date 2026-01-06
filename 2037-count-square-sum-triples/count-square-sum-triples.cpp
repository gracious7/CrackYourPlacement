class Solution {
public:
    bool f(int c, int n){
        int x = sqrt(c);
        if(x*x == c && x <= n) return true;
        return false;
    }
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                int c = i*i + j*j;
                if(f(c, n)) ans++;
            }
        }

        return ans;
    }
};