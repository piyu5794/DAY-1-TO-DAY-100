class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n =nums.size();
        int sum =0;
        for(int i=0 ;i<n; i++){
            
            vector<int> v;
            for(int j =i; j<n; j++){
                set<int> st;
                v.push_back(nums[j]);
                for(int ele :v) st.insert(ele);
                int x =st.size();
                sum += x*x;
            }
        }
        return sum;
    }
};