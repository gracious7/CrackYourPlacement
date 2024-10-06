class Solution {
public:
    bool f(vector<int>&a, int h, int k){
        long long cnt = 0;
        int n = a.size();
        for(int i = 0; i<n; i++){
            cnt += a[i]/k ;
            if(a[i]%k != 0) cnt++;
            
        }
        
        return cnt <= h;

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // int mn = *min_element(piles.begin(), piles.end());
        int mx = *max_element(piles.begin(), piles.end());

        int s = 1, e = mx;
        int ans = 0;
        while(s <= e){
            int m = s + (e-s)/2;
            if(f(piles, h, m)){
                ans = m;
                e = m-1;
            }
            else s = m+1;

        }
        
        return ans;
    }
};