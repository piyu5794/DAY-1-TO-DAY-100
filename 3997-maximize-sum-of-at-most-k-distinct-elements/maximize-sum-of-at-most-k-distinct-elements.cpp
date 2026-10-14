class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_map<int ,int> mp;
        vector<int> v;
        sort(nums.begin(), nums.end(), greater<int>());
        int n =nums.size();
        for(int i= 0; i<n; i++){
            int x =nums[i];
            if(mp.find(x) !=mp.end()){
                continue;
            }
            v.push_back(x);
            if(v.size() ==k) break;
            mp[x]++;
        }
        return v;
    }
};