class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int r = grid.size();
        int c = grid[0].size();
        
        // Boundary and visitation checks
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 'X' || visited[i][j]) {
            return;
        }

        // Mark cell as visited
        visited[i][j] = true;

        // Explore neighbors
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int ci = i + drow[k];
            int cj = j + dcol[k];
            dfs(ci, cj, grid, visited);
        }
    }

    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if (r == 0) return;
        int c = board[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c, false));

        // Start DFS/BFS from all border 'O' cells
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) && board[i][j] == 'O' && !visited[i][j]) {
                    dfs(i, j, board, visited);
                }
            }
        }

        // Update board based on the visited cells
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';  // Cell is surrounded
                }
            }
        }
    }
};
