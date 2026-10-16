class Solution {
public:
    int jump(vector<int>& nums) {
        int n =nums.size();
        int count=0, end =0, jump=0;
        for(int i=0; i<n-1; i++){
            count =max(count ,i +nums[i]);
            if(i==end){
                jump++;
                end =count;
            }
        }
        return jump;
    }
};