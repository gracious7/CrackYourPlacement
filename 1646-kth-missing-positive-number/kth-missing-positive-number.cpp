class Solution {
public:

    int findKthPositive(vector<int>& a, int k) {
        int cnt = 0;
        int i = 0;
        int c = 0;
        while(cnt-c < k){
            cnt++;
            if(cnt == a[i]){
                c++;
                if(i< a.size()-1) i++;
            }
            if(cnt-c == k) return cnt;
        }
        
        return cnt ;
    }
};