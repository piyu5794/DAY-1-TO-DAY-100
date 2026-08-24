class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int ele : nums)
            mp[ele]++;

        int n = nums.size();
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (mp.find(i) != mp.end())
                continue;
            else
                ans.push_back(i);
        }
        return ans;
    }
};