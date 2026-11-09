class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> st;
        int n =nums.size();
        for(int i=0 ;i<n; i++){
            st.insert(nums[i]);
        }
        int ele = *min_element(nums.begin(), nums.end());
        int x = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        while(ele <=x){
            if(st.find(ele) ==st.end()){
                ans.push_back(ele);
            }
            ele++;
        }
        return ans;
    }
};