class Solution {
public:

    bool can(vector<int>&a, int d, int w){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i<a.size(); i++){
            if(sum + a[i] <= w){
                sum += a[i];
            }
            else{
                cnt++;
                sum = a[i];
            }
            if(cnt > d) return false;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end()); 
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(s <= e){
            int m = s + (e-s)/2;
            if(can(weights, days, m)){
                ans = m;
                e = m-1;
            }
            else s = m+1;
        }
        return ans;
    }
};