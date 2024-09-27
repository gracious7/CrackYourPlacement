class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.rbegin(), nums.rend());
        // return nums[k-1];

        priority_queue<int, vector<int>, greater<int> >pq;

        for(auto x: nums){
            pq.push(x);
            if(pq.size() > k) pq.pop();
        }

        int ans = pq.top();

        return ans;
    }
};