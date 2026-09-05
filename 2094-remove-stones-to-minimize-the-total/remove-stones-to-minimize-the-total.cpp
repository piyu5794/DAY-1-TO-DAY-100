class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for (int x : piles) {
            pq.push(x);
        }

        while (k> 0) {
            int x = pq.top() +1;
            pq.pop();

            x = x / 2;
            pq.push(x);
            k--;
        }

        int ans = 0;

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};