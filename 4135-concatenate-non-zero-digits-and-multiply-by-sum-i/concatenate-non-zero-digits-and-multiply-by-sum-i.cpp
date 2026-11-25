class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long x =0;
        for(char ch : s){
            if(ch =='0'){
                continue;
            }
            x = x*10 + (ch- '0');
            
        }
        long long y =x, sum =0;
        while(y >0){
            sum += y%10;
            y =y/10;
        }
        return x *sum;
    }
};