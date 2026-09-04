class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;        
        for(int x :nums) pq.push(x);
        int count =0;
        long long x,y;
        while(pq.size() >1){
            if(pq.top() >=k) return count;
            x =pq.top();
            pq.pop();
            y =pq.top();
            pq.pop();
        
            pq.push(x*2 +y);
            count++;
        } 
        return count;
    }
};