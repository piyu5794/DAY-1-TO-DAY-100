class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26,-1);
        int n =s.size();
        for(int i= 0; i<n; i++){
            last[s[i] -'a'] =i;
        }

        stack<char> st;
        vector<bool> used(26, false);
        for(int i=0 ;i<n ;i++){
            char c =s[i];
            if(used[c -'a']) continue;
            
            while(!st.empty() && st.top() >c && last[st.top() -'a'] >i){
            
                used[st.top() -'a'] =false;
                st.pop();
            }
            st.push(c);
            used[c -'a'] =true;
        }
        string ans="";
        while(!st.empty()){
            ans =st.top() +ans;
            st.pop();
        }
        return ans;
    }
};