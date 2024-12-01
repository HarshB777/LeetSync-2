class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int lastTime = 0;
        
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};

        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ci = i + drow[k];
                int cj = j + dcol[k];

                if (ci >= 0 && ci < r && cj >= 0 && cj < c && grid[ci][cj] == 1) {
                    grid[ci][cj] = 2;
                    q.push({{ci, cj}, time + 1});
                }
            }

            lastTime = max(time, lastTime);
        }

        // Check if there's any fresh orange left
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1; // If any fresh orange is still left
                }
            }
        }

        return lastTime;
    }
};
