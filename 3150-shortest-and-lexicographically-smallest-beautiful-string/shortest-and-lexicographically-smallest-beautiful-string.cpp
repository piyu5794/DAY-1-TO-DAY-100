class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0, count = 0;
        string ans = "",curr ="";
        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1')
                count++;
            while (count > k) {
                if (s[left] == '1')
                    count--;
                left++;
            }
            if (count == k) {
                while (s[left] == '0')
                    left++;
                curr = s.substr(left, right - left + 1);
                
                if (ans.size() > curr.size() || ans.size() == 0 ||
                (curr.size() == ans.size() && curr < ans))
                ans = curr;
            }

            
        }
        return ans;
    }
};