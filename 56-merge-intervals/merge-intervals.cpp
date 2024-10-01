class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ps =-1;
        int pe = -1;
        vector<vector<int>>ans;
      
        for(int i =0; i<n; i++){
            int s = arr[i][0];
            int e = arr[i][1];
            if(ans.size() == 0) ans.push_back({s, e});
            else{
                int nn= ans.size()-1;
                int ps = ans[nn][0];
                int pe = ans[nn][1];
                if(s <= pe and e > pe){
                    // pe = e;
                    ans[nn][1] = e;
                }
                else if(s > pe) ans.push_back({s, e});
            }
        }

        return ans;

    }
};