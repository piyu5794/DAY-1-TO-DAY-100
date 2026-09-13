class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> v;
        int n =nums.size();
        long long ans =0;
        for(int ele :nums){
            while(!v.empty() && v.back() >ele){
                v.pop_back();
            }
             ans += lower_bound(v.begin(),v.end(),ele) - v.begin();

             v.push_back(ele);
        }
        return ans;
    }
};