class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int ele : nums) {
            auto idx = lower_bound(v.begin(), v.end(), ele);
            int i = idx - v.begin();
            ans.push_back(i);
        }
        return ans;
    }
};