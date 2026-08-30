class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        int n = path.size();
        for (int i = 0; i < n;) {
            while (i < n && path[i] == '/')
                i++;

            string s = "";
            while (i < n && path[i] != '/'){
                 s += path[i];
                 i++;
            }

            if (s == "" || s == ".")
                continue;
            if (s == "..") {
                if (!st.empty())
                    st.pop();
            } else
                st.push(s);
        }
        string ans;
        while (!st.empty()) {
            ans = '/' + st.top() + ans;
            st.pop();
        }
        if (ans.empty())
            return "/";
        else
            return ans;
    }
};