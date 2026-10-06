// class Solution {
// public:
//    int lengthOfLongestSubstring(string s) {
//        vector<bool> a(95, false);
//        int ans = 0, l = 0, r = 0;
       
//        while (r < s.size()) {
//            if ( !a[ s[r] - 32 ] ) {
//                ans = max(ans, r - l + 1);
//                a[ s[r++] - 32 ] = true;
//            }
//            else a[ s[l++] - 32 ] = false;
//        }

//        return ans;
//    }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int ans =0;
//         for(int i=0; i<s.size(); i++){
//             int j= i;
//             int count =0;
//             unordered_map<char, int> mp;
//             while(j <s.size()){
//                 mp[s[j]]++;
//                 if(mp[s[j]] >1) break;
//                 count++;
//                 j++;
//             }
//             ans =max(ans, count);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0, ans =0;
        unordered_map<char ,int> mp;
        for(int i=0; i< s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]] >1){
                mp[s[left]]--;
                left++;
            }
            ans =max(i -left +1, ans);
        }
        return ans;
    }
};