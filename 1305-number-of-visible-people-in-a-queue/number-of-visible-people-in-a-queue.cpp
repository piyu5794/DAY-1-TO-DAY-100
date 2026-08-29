class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size(), count;
        vector<int> ans(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            count = 0;
            while (!st.empty() && heights[i] > st.top()) {
                count++;
                st.pop();
            }
            if (!st.empty())
                count++;
            ans[i] = count;

            st.push(heights[i]);
        }
        return ans;
    }
};