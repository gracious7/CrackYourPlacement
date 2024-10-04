class Solution {
public:
    long long dividePlayers(vector<int>& sk) {
        sort(sk.begin(), sk.end());
        int n = sk.size();

        long long chem = 0, part = 0;
        part = sk[0] + sk[n-1];
        for(int i = 0; i<n/2; i++){
            if(sk[i] +sk[n-i-1] != part){
                return -1;
            }
            chem += sk[i]*sk[n-1-i];
        }
        return chem;

    }
};