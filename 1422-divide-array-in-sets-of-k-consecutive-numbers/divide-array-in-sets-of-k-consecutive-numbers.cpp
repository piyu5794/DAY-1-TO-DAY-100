class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() %k !=0) return false;
        map<int, int> mp;
        for(int ele :nums){
            mp[ele]++;
        }
        
        while(!mp.empty()){
            auto ele =mp.begin();
            int x =ele->first;
            for(int i=0; i<k;i++){
                if(mp.find(x) !=mp.end()){
                    mp[x]--;
                    if(mp[x]==0) mp.erase(x);
                    x++;
                }
                else return false;
            }
        }
        return true;
    }
};