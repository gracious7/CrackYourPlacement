class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v(26, 0);
        sort(s1.begin(), s1.end());
        int l = s1.size();

        int n = s2.size();
        for(int i = 0;i<=n-l; i++){
            string ss = s2.substr(i, l);
            sort(ss.begin(), ss.end());

            // cout<<s1<<' '<<ss<<endl;
            if(ss == s1) {

                return true;
            }
        }
        return false;

    }
};