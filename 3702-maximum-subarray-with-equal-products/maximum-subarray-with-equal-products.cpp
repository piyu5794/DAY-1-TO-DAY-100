class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n =nums.size();
        int ans =0;
        for(int i=0; i<n;i++){
            __int128 a=1;
            long long b=1, c=0;
            for(int j=i; j<n; j++){
                
                a *=nums[j];
                b =lcm(b ,(long long)nums[j]);
                c =gcd(c,(long long) nums[j]);

                if(a ==(__int128)b *c){
                    ans =max(ans, j-i+1);
                }
                if(a >(__int128)b *c){
                    break;
                }
            }
        }
        return ans;
    }
};