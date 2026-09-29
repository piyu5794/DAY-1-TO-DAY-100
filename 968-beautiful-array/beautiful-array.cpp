class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);
        while(ans.size() <n){
            vector<int> temp;
            for(int ele :ans){
                int odd =2*ele -1;
                if(odd<=n) temp.push_back(odd);
            }
            for(int ele :ans){
                int even = 2*ele;
                if(even<=n) temp.push_back(even);
            }
            ans =temp;
        } 
        return ans;     
    }
};