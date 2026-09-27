class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char, int> mp1;
        unordered_map<int, int> mp2;

        for(char ch :suits){
            mp1[ch]++;
        }
        for(int x :ranks){
            mp2[x]++;
        }
        for(auto ele :mp1){
            int x =ele.second;
            if(x==5) return "Flush";
        }
        bool flag =false;
        for(auto ele :mp2){
            int x =ele.second;
            if(x >=3) return "Three of a Kind";
            if(x ==2) flag =true;
        }
        if(flag) return "Pair";
        return "High Card";
    }
};