class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(char ch :chars){
            mp[ch]++;
        }
        int ans =0;
        for(string s :words){
            unordered_map<char ,int> temp =mp;
            bool flag =true;
            for(char ch :s){
                if(temp.find(ch) !=temp.end() && temp[ch] >0) temp[ch]--;
                else {
                    flag =false;
                    break;
                }
            }
            if(flag) ans +=s.size();
        }
        return ans;
    }
};