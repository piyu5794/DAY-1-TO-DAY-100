class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum =0;
        for(int ele :stones){
            sum +=ele;
        }
        int tar =sum/2;
        vector<bool> dp(sum/2 +1, false);
        dp[0] =true;
        for(int stone : stones){
            for(int i =tar; i>=stone; i--){
                dp[i] =dp[i] || dp[i- stone];
            }
        }
        for(int i =tar; i>=0; i--){
            if(dp[i]){
                return sum - 2*i;
            }
        }
        return 0;
    }
};