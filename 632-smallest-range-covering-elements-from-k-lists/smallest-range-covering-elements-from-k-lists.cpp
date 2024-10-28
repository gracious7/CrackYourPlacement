class Solution {
public:
    using int2=pair<int, int>;
    using int3=tuple<int, short, char>;// (x, list id=i, index=j)
    static inline bool less(int2& x, int2& y){
        auto [a, b]=x;
        auto [c, d]=y;
        if (b-a==d-c) return a<c;
        return b-a<d-c;
    }

    static vector<int> smallestRange(vector<vector<int>>& nums) {
        const int n=nums.size();
        priority_queue<int3> pq;// maxheap
        int xMin=INT_MAX;
        for(int i=0; i<n; i++){
            int x=nums[i].back();// max element in nums[i]
            pq.emplace(x, i, nums[i].size()-1);
            xMin=min(xMin, x);
        }
        int2 min_range={0, INT_MAX};
        while(pq.size()==n){
            auto [xMax, i, j]=pq.top();
            pq.pop();
            int2 range={xMin, xMax};
            if (less(range, min_range)) min_range=range;
            if (j>0){// shrink the range if possible
                int x=nums[i][j-1];
                pq.emplace(x, i, j-1);
                xMin=min(x, xMin);
            }
        }
        return {min_range.first, min_range.second};
    }
}; 

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();