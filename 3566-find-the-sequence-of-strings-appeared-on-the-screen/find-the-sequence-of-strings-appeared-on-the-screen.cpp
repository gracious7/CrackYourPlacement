class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        int n= target.size();
        string ss = "";
        for(int i = 0; i<n; i++){
            char ch = target[i];
            string tmp = "";
            for(char c = 'a'; c <= ch; c++){
                tmp = ss+c;
                ans.push_back(tmp);
            }
            ss = tmp;

        }
        return ans;
    }
};