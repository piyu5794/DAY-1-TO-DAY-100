class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n =nums.size();
        //sort(nums.begin(), nums.end());
        vector<int> v;
        for(int ele :nums){
            v.push_back(1LL *ele *ele);
        }
        sort(v.begin(), v.end());
        long long sum =0;
        for(int i=n/2; i<n; i++){
            sum += v[i];
        }
        for(int i=0; i<n/2;i++){
            sum -= v[i];
        }
        return sum;
    }
};