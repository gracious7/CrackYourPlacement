class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<long long, pair<int, int>>>pq;

        for(auto x: points){
            int a = abs(x[0]*x[0]);
            int b = abs(x[1]*x[1]);
            pq.push({ a+b , {x[0], x[1]}});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x= it.second.first, y = it.second.second;
            ans.push_back({x, y});
        }

        return ans;

    }
};