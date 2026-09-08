class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string ,string>mp;
        for(auto ele :paths){
            mp[ele[0]] =ele[1];
        }
        string ans =paths[0][0];
        for(auto ele :mp){
            
            if(mp.find(ans) != mp.end()){
                ans =ele.second;
            }
            else break;
        }
        return ans;
    }
};