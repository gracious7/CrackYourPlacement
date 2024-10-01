class Solution {
public:
    string reverseWords(string s) {
        vector<string>w;
        stringstream ss(s);
        string ds;
        while(ss >> ds){
            w.push_back(ds);
        }
        string ans = "";
        reverse(w.begin(), w.end());
        for(int i =0; i<w.size(); i++){
            if(i != w.size()-1){
                ans += w[i]+" ";
            }
            else ans += w[i];
        }
        return ans;
    }
};