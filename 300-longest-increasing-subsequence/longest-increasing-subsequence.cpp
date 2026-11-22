// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> ans;
//         for(int num :nums){
//             int lo =0, hi=ans.size();
//             while(lo< hi){
//                 int mid =(lo+hi)/2;
//                 if(num >ans[mid]) lo= mid+1;
//                 else hi =mid;
//             }
//             if(lo ==ans.size()) ans.push_back(num);
//             ans[lo] =num;
//         }
//         return ans.size();
//     }
// };

class Solution {
public:
    int n;
    vector<int> arr;
    vector<vector<int>> dp;
    int solve(int prev ,int curr){
        if(curr ==n) return 0;

        if(dp[prev+1][curr] !=-1){
            return dp[prev+1][curr];
        }

        int take =0;
        if(prev ==-1 || arr[prev] <arr[curr]){
            take =1 +solve(curr, curr+1);
        } 
        int skip =solve(prev, curr+1);

        return dp[prev+1][curr] = max(take, skip);
    }
    int lengthOfLIS(vector<int> &nums){
        arr =nums;
        n =nums.size();

        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return solve(-1,0);
    }
};