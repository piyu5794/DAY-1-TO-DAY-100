class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        for(auto ele :nums1){
            mp[ele[0]] +=ele[1];
        }
        for(auto ele :nums2){
            mp[ele[0]] +=ele[1];
        }

        vector<vector<int>> ans;
        for(auto ele :mp){
            ans.push_back({ele.first, ele.second});
        }
        
        return ans;
    }
};