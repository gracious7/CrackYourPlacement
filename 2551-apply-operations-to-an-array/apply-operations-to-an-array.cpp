class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int count1=count(nums.begin(),nums.end(),0);
        vector<int> temp;
        for(auto &x:nums){
            if(x!=0) temp.push_back(x);
        }
        while(count1--){
            temp.push_back(0);
        }
        return temp;
    }
};