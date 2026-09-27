class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int idx =0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] %2==0){
                swap(nums[idx], nums[i]);
                idx++;
            }
           
        }
        return nums;
    }
};