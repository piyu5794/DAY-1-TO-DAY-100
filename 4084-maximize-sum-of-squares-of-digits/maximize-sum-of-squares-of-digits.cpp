class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";
        string ans ="";
        while(num >0){
            if(sum >=9){
                ans += to_string(9);
                sum -=9;
            }
            else {
                ans +=to_string(sum);
                sum -=sum;
            }
            num--;
        }
        return ans;
    }
};