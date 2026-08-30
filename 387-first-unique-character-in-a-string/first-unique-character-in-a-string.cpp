class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        int idx;
        bool flag;
        for(int i=0;i<n;i++){
            idx =i;
            flag =true;
            for(int j=0;j<n;j++){
                if(i!=j && s[i]==s[j]){
                    flag= false;
                    break;
                }
            }
            if(flag==true) break;
        }
        if(flag==true) return idx;
        return -1;
    }
};