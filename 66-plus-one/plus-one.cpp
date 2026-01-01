class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
     int n = digits.size();
     int c = 1; 
     vector<int>ans;
     for(int i = n-1; i>= 0; i--){
        if(digits[i] == 9 && c == 1){
            ans.push_back(0);
        }
        else{
            ans.push_back(digits[i]+c);
            c = 0;
        }
     }   
     if(c == 1) ans.push_back(1);
     reverse(ans.begin(), ans.end());
     return ans;
    }
};