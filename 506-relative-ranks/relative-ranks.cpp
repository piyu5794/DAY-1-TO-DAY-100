class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int n =score.size();
        for(int i =0; i<n ;i++){
            pq.push({score[i] ,i});
        }

        vector<string> ans(n);
        int rank =1;
        while(!pq.empty()){
            int idx =pq.top().second;
            pq.pop();
             if (rank == 1)
                ans[idx] = "Gold Medal";
            else if (rank == 2)
                ans[idx] = "Silver Medal";
            else if (rank == 3)
                ans[idx] = "Bronze Medal";
            else ans[idx] =to_string(rank);

            rank++;
        }
        return ans;
    }
};