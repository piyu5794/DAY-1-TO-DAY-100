class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans =0;
        for(int num :nums){
            string s= to_string(num);
            int t =s.size();
            if(t %2==0) ans++;
        }
        return ans;
    }
};