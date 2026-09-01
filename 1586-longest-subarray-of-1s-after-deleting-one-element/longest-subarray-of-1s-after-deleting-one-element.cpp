class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int len=0, maxlen= -1;
         int k=1;
        int n= nums.size();
        int i=0, j=0;
        int flips=0;
        //if(k>=n) return n;
        while(j<n){
            
            if(nums[j]==1) j++;
            else{
                if(flips<k){
                    j++;
                    flips++;
                }
                else{
                    len =j-i;
                    maxlen= max(len,maxlen);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                    
                }
            }
            
        }
        len =j-i;
        maxlen= max(len,maxlen);
        return maxlen-1;
    }
};