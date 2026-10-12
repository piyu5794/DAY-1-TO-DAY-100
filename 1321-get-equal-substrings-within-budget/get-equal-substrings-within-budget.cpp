class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left =0, cost =0, ans =0;
        for(int i=0 ;i<s.size(); i++){
            cost += abs(s[i] -t[i]);
            
            while(cost >maxCost){
                cost -= abs(s[left] -t[left]);
                left++;
            }
            ans =max(ans ,i -left +1);
        }
        return ans;
    }
};