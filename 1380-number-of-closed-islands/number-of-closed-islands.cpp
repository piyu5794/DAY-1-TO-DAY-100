class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == 1 || vis[i][j] == 1) {
            return;
        }

        vis[i][j] = 1;

        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i, j + 1);
        dfs(grid, vis, i, j - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Visit all land connected to the boundary
        for (int i = 0; i < m; i++) {
            dfs(grid, vis, i, 0);
            dfs(grid, vis, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(grid, vis, 0, j);
            dfs(grid, vis, m - 1, j);
        }

        int count = 0;

        // Count closed islands
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0 && vis[i][j] == 0) {
                    count++;
                    dfs(grid, vis, i, j);
                }
            }
        }

        return count;
    }
};

// class Solution {
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> vis(m, vector<int>(n, 0));

//         int dx[4] = {1, -1, 0, 0};
//         int dy[4] = {0, 0, 1, -1};

//         auto bfs = [&](int i, int j) {
//             queue<pair<int, int>> q;
//             q.push({i, j});
//             vis[i][j] = 1;

//             while (!q.empty()) {
//                 auto [x, y] = q.front();
//                 q.pop();

//                 for (int k = 0; k < 4; k++) {
//                     int nx = x + dx[k];
//                     int ny = y + dy[k];

//                     if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
//                         grid[nx][ny] == 0 && !vis[nx][ny]) {
//                         vis[nx][ny] = 1;
//                         q.push({nx, ny});
//                     }
//                 }
//             }
//         };

//         // Visit boundary-connected land
//         for (int i = 0; i < m; i++) {
//             if (grid[i][0] == 0 && !vis[i][0]) bfs(i, 0);
//             if (grid[i][n-1] == 0 && !vis[i][n-1]) bfs(i, n-1);
//         }

//         for (int j = 0; j < n; j++) {
//             if (grid[0][j] == 0 && !vis[0][j]) bfs(0, j);
//             if (grid[m-1][j] == 0 && !vis[m-1][j]) bfs(m-1, j);
//         }

//         int count = 0;

//         // Count closed islands
//         for (int i = 1; i < m-1; i++) {
//             for (int j = 1; j < n-1; j++) {
//                 if (grid[i][j] == 0 && !vis[i][j]) {
//                     count++;
//                     bfs(i, j);
//                 }
//             }
//         }

//         return count;
//     }
// };