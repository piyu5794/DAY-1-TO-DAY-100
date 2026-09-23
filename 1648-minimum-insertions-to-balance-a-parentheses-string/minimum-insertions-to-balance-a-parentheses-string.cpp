class Solution {
public:
    int minInsertions(string s) {

        stack<char> st;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push('(');
            }
            else {

                // Check whether we have ))
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Only one ')' → insert another ')'
                    ans++;
                }

                // Match )) with (
                if (!st.empty()) {
                    st.pop();
                }
                else {
                    // No '(' → insert '('
                    ans++;
                }
            }
        }

        // Every remaining '(' needs ))
        ans += 2 * st.size();

        return ans;
    }
};