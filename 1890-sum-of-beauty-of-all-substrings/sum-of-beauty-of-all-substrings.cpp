class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        vector<int>dv(26, 0);
        vector<vector<int>>v(n, vector<int>(26, 0));
        for(int i = 0; i<n; i++){
            int x = s[i]-'a';
            dv[x]++;
            v[i] = dv;
            for(auto dx: dv) cout<<dx<<' ';
            cout<<endl;
        }       
        int ans = 0;
        for(int i =0;i<n; i++){
            for(int j = i; j<n; j++){
                vector<int>vj = v[j];
                int mx =0, mn = 5001;
                if(i != 0){
                    vector<int>vi = v[i-1];
                    for(int k = 0;k<26;k++) vj[k] -= vi[k];
                }
                for(int k = 0; k<26; k++){
                    if(vj[k] != 0){
                        mx = max(mx, vj[k]);
                        mn = min(mn, vj[k]);
                    }
                }
                


                ans += mx-mn;
            }
        }
        return ans;
    }
};