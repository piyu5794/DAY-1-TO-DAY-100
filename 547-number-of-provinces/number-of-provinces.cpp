class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[i] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
    void bfs(int i, vector<vector<int>>& isConnected, vector<int>& visited){
        visited[i] =true;
        queue<int> q;
        q.push(i);
        while(q.size()>0){
            int node= q.front();
            q.pop();
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[node][j]==1 && !visited[j]){
                    visited[j] =true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i, isConnected, visited);
                count++;
            }
        }

        return count;
    }
};