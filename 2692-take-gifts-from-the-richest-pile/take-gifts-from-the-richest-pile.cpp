class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int ele :gifts){
            pq.push(ele);
        }
        for(int i =0; i<k;i++){
            int x =pq.top();
            pq.pop();
            pq.push(sqrt(x));
        }
        long long ans =0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};