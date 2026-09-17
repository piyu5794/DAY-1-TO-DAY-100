// class Solution {
// public:
//     int minSumOfLengths(vector<int>& arr, int target) {
//         vector<vector<int>> ans;
//         int i =0, n =arr.size();
//         while(i <n){
//             int sum =0, j =i;
//             vector<int> v;
//             while(j <n && sum <=target){
//                 sum +=arr[j];
//                 v.push_back(arr[j]);
//                 if(sum ==target){
//                     ans.push_back({i ,j});
//                     //i =j+1;
//                     break;
//                 }
//                 j++;
//             }
//             i++;
//         }
//         if(ans.size() <2) return -1;
//         int res = INT_MAX;
//         for (int i = 0; i < ans.size(); i++) {
//             for (int j = i + 1; j < ans.size(); j++) {

//                 // Check non-overlapping
//                 if (ans[i][1] < ans[j][0] ||
//                     ans[j][1] < ans[i][0]) {

//                     int len1 = ans[i][1] - ans[i][0] + 1;
//                     int len2 = ans[j][1] - ans[j][0] + 1;
//                     res = min(res, len1 +len2);
//                 }
//             }
//         }
//         if(res ==INT_MAX) return -1;
//         return res;
//     }
// };

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);

        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        int minLen = INT_MAX;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (mp.find(sum - target) != mp.end()) {
                int start = mp[sum - target] + 1;
                int len = i - start + 1;

                // Previous subarray must end before 'start'
                if (start > 0 && best[start - 1] != INT_MAX) {
                    ans = min(ans, len + best[start - 1]);
                }

                minLen = min(minLen, len);
            }

            if (i == 0)
                best[i] = minLen;
            else
                best[i] = min(best[i - 1], minLen);

            mp[sum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};