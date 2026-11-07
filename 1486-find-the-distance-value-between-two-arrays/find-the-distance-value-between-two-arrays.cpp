class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int cnt = 0;

        for (int ele : arr1) {
            int lo = 0, hi = arr2.size() - 1;
            bool flag = true;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (abs(arr2[mid] - ele) <= d) {
                    flag = false;
                    break;
                } else if (arr2[mid] < ele) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (flag)
                cnt++;
        }

        return cnt;
    }
};