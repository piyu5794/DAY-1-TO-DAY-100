class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch=='(') st.push(i);
            else if(ch ==')'){
                int x = st.top();
                st.pop();

                reverse(s.begin()+ x+1 ,s.begin() +i);
            }
        }
        string ans ="";
        for(char ch :s){
            if(ch =='(' || ch==')') continue;
            ans +=ch;
        }
        return ans;
    }
};