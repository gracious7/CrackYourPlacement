class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st;
        for(auto x: arr) st.insert(x);

        unordered_map<int, int>m;
        int r = 1;
        for(auto x: st){
            m[x]=r;
            r++;
        }

        for(int i =0; i<arr.size(); i++){
            arr[i] = m[arr[i]];
        }
        return arr;


    }
};