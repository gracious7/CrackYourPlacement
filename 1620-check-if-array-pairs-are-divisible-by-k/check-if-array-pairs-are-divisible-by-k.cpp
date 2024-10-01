class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>v(k, 0);
        for(int i = 0;i<n; i++){
            int mod;
            if(arr[i] < 0){
                mod = (k - abs(arr[i]) % k) % k;
            }
            else mod = arr[i]%k;
            v[mod]++;
        }
        if(v[0]%2 != 0) return false;
        for (int i = 1; i <= k/2; i++) {
            if (i == k - i) { 
                if (v[i] % 2 != 0) return false;
            } else if (v[i] != v[k - i]) {
                return false;
            }
        }
        return true;
        
    }
};