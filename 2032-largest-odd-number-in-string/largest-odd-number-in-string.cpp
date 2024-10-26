class Solution {
public:
    string largestOddNumber(string num) {
        int ind = -1;
        for(int i =0; i<num.size(); i++){
            int x = num[i]-'0';
            if(x%2 == 1){
                ind =i;
            }
        }
        string ans = num.substr(0, ind+1);
        return ans;
    }
};