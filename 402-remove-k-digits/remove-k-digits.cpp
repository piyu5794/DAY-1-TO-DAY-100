class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for(char c :num){
            while(!st.empty() && k >0 &&st.top() >c){ 
                k--;
                st.pop();
            }
            st.push(c);
        }
        while(k >0){
            st.pop();
            k--;
        }
        string ans ="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int j=0;
        while(j <ans.size() && ans[j]=='0'){
            j++;
        }
        ans =ans.substr(j);
        if(ans.size() ==0) return "0";
        return ans;
    }
};