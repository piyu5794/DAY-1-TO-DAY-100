class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum= 0;
        for(int ele :arr){
            sum +=ele;
        }
        if(sum %3 !=0) return false;
        sum =sum/3;
        int count =0, a=0;

        for(int ele :arr){
            a +=ele;
            if(a ==sum){
                count++;
                a =0;
            }
        }
        return (count>=3);
    }
};