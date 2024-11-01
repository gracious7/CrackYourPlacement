class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        int n = nums.size();
        double sum = 0;

        

        for(int i =0; i<k; i++) sum += nums[i];

        double avg = sum/k;
        ans = max(ans, avg);

        int j = 0;
        for(int i =k; i<n; i++){

            sum = sum - nums[j] + nums[i];
            j++;

            double avg = sum/k;
            ans = max(ans, avg);

        }

        return ans;
    }
};