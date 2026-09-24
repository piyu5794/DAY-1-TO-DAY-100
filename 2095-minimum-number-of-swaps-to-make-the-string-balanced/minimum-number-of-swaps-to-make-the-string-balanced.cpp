class Solution {
public:
    int minSwaps(string s) {
        int count =0;
        int ans =0;
        for(char ch :s){
            if(ch =='['){
                count++;
            }
            else count--;

            ans =min(count, ans);
        }
        return (-ans +1)/2;
    }
};