class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for (auto ele : reservedSeats)
            mp[ele[0]].push_back(ele[1]);
        int ans = 2 * n;
        for (auto ele : mp) {
            bool left = true, right = true, middle = true;
            for (int seat : ele.second) {
                if (seat >= 2 && seat <= 5)
                    left = false;
                if (seat >= 4 && seat <= 7)
                    middle = false;
                if (seat >= 6 && seat <= 9)
                    right = false;
            }
            if (left && right)
                continue;
            if (left || right || middle)
                ans--;
            else
                ans -= 2;
        }
        return ans;
    }
};