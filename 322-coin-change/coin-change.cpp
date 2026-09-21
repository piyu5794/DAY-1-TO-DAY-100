class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= amount;
        vector<int> dp(n+1, n+1);
        dp[0] =0;
        for(int i =1; i<=n; i++){
            for(int ele :coins){
                if(i -ele >=0){
                    dp[i] =min(dp[i], 1+ dp[i- ele]);
                }
            }
        }
        if(dp[n] >n) return -1;
        return dp[n];
    }
};