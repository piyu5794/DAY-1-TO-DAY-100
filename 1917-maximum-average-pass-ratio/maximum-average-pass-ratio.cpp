class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<
            pair<double, pair<int, int>>,
            vector<pair<double, pair<int, int>>>,
            greater<pair<double, pair<int, int>>>
        > pq;

        for (auto &c : classes) {

            int pass = c[0];
            int total = c[1];

            pq.push({
                -(double)((double)(pass + 1) / (total + 1) - (double)pass / total),
                {pass, total}
            });
        }

        while (extraStudents--) {

            auto [gain, data] = pq.top();
            pq.pop();

            int pass = data.first;
            int total = data.second;

            pass++;
            total++;

            pq.push({
                -(double)((double)(pass + 1) / (total + 1) - (double)pass / total),
                {pass, total}
            });
        }

        double ans = 0;

        while (!pq.empty()) {

            auto [gain, data] = pq.top();
            pq.pop();

            ans += (double)data.first / data.second;
        }

        return ans / classes.size();
    }
};