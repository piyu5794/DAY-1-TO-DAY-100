class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum =0;
        for(int ele :arr){
            sum +=ele;
        }
        int a=0,b=0;
        for(int x :arr){
            a =max(0, a +x);
            b =max(b ,a);
        }
        if(k==1) return b;

        long long curr= 0, best =0;
        for(int j=0; j<=1; j++){
            for(int ele :arr){
                curr =max(0LL, curr +ele);
                best =max(best ,curr);
            }
        }
        if(k >2 && sum>0){
            best += (k-2LL)*sum;
        }
        return best %1000000007;
    }
};