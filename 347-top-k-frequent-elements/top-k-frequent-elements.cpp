class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        unordered_map<int, int> m;
        vector<int> ans;
        priority_queue<p, vector<p>, greater<p>> pq;
        for (int ele : nums)
            m[ele]++;
    
        for (auto ele : m) {
            int a = ele.first;
            int b = ele.second;
            pair<int, int> pr = {b, a};
            pq.push({b, a});
            if (pq.size() > k)
                pq.pop();
        }
        while (pq.size() > 0) {
            auto ele = pq.top();
            ans.push_back(ele.second);
            pq.pop();
        }
        return ans;
    }
};