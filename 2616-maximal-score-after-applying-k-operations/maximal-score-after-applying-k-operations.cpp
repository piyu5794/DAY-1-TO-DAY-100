class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int ele :nums){
            pq.push(ele);
        }
        long long ans =0;
        while(k >0){
            double x =pq.top();
            pq.pop();
            ans +=x;
            pq.push(ceil(x /3));
            k--;
        }
        return ans;
    }
};