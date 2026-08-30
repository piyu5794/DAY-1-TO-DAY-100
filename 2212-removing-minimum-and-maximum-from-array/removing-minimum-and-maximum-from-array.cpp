class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx = INT_MIN, mn = INT_MAX;
        int n = nums.size(), j = -1, k = -1;
        for (int i = 0; i < n; i++) {
            if (mn > nums[i]) {
                mn = nums[i];
                j = i;
            }
            if (mx < nums[i]) {
                mx = nums[i];
                k = i;
            }
        }
        int left = min(j, k);
        int right = max(j, k);

        int ans1 = right + 1;
        int ans2 = n - left;

        int ans3 = left + 1 + n - right;

        return min({ans1, ans2, ans3});
    }
};