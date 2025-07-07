class FindSumPairs {
public:
    vector<int> nums1, nums2; 
    unordered_map<int, int> m, mm;

    FindSumPairs(vector<int>& anums1, vector<int>& bnums2) {
        nums1 = anums1;
        nums2 = bnums2;
        for (auto x : nums1) {
            m[x]++;
        }
        for (auto x : nums2) {
            mm[x]++;
        }
    }

    void add(int index, int val) {
        mm[nums2[index]]--;        
        nums2[index] += val;       
        mm[nums2[index]]++;        
    }

    int count(int tot) {
        int res = 0;
        for (auto& [num, freq] : m) {
            int complement = tot - num;
            res += freq * mm[complement];
        }
        return res;
    }
};
