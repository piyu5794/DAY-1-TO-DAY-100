class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k,0);
        vector<long long> ans(k, 0);

        for(int ele :nums){
            vector<long long> ndp(k,0);
            int val =ele %k;
            ndp[val]++;
            for(int r =0; r< k; r++){
                if(dp[r]==0) continue;

                int newR =(long long)r *val %k;
                ndp[newR] +=dp[r];
            }

            for(int r =0 ;r<k; r++){
                ans[r] +=ndp[r];
            }
            dp= ndp;
        }
        return ans;
    }
};