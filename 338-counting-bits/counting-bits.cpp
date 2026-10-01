// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n+1);
//         ans[0] =0;
//         for(int i=1; i<=n; i++){
//             int count =0;
//             int k= i;
//             while(k >0){
//                 if(k %2==1) count++;
//                 k =k/2;
//             }
//             ans[i] =count;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1 ,0);
        for(int i=1;i <=n;i++){
            ans[i] =ans[i/2] +i%2;
        }
        return ans;
    }
};