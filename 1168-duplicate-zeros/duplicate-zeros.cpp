class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>a;
        int n = arr.size();
        int i = 0;
        for(auto x: arr){
            if(i >= n) break;
            if(x == 0){
                a.push_back(0);
                i++;
                if(i >= n) break;
                a.push_back(0);
                i++;
                if(i >= n) break;
            }
            else{
                 a.push_back(x);
                 i++;
                if(i >= n) break;
            }
            
        }
        arr = a;
    }
};