class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count =0, mx =0;
        for(int i =0; i<s.size(); i++){
            
            if(s[i] =='(') st.push('(');
            else if(s[i] ==')') st.pop();

            count =st.size();
            mx =max(count, mx);
        }
        return mx;
    }
};