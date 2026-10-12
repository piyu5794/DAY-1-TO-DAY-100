class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char ,int> mp1 ,mp2;
        for(auto s :word1){
            mp1[s]++;
        }
        for(auto s :word2) mp2[s]++;
        for(auto ele :mp1){
            int x =ele.first;
            if(mp2.find(x) ==mp2.end()) return false;
        }
        vector<int> v1, v2;
        for(auto ele :mp1) v1.push_back(ele.second);
        for(auto ele :mp2) v2.push_back(ele.second);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1==v2;
    }
};