class Solution {
public:
    string decodeMessage(string key, string message) {
        char i ='a';
        unordered_map<char, char>mp;
        for(char ch :key){
            if(ch !=' ' && mp.find(ch) ==mp.end()){
                mp[ch] =i;
                i++;
            }
        }
        string ans ="";
        for(char ch :message){
            if(ch ==' ') ans +=ch;
            else{
                ans += mp[ch];
            }
        }
        return ans;
    }
};