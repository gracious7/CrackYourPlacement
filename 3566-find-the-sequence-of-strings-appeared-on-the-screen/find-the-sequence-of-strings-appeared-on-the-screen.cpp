class Solution {
public:
    vector<string> stringSequence(string target) {
        int n = target.size();
        string s = "";
        vector<string>ans;
        for(int i = 0;i<n; i++){
            string ss= s;
            char c = 'a';
            ss = s+c;
            // c++;
            ans.push_back(ss);
            while(c < target[i]){
                c++;
                ss = s + c;
                ans.push_back(ss);

            }
            s = ss;
        }
        return ans;
    }
};