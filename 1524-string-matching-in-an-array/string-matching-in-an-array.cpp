class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a, const string &b){
            return a.length() < b.length();
            });
        vector<string> v;

        // for(string s : words){
        //     cout << s << "  " ;
        // }

        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i].size()!=words[j].size()){
                    size_t pos = words[j].find(words[i]);
                    if(pos != string::npos){
                        v.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return v;
    }
};