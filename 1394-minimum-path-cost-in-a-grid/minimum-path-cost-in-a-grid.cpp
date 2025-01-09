class Solution {
public:
    void help(int val, int curr, int curr_row, vector<vector<int>> &grid, vector<vector<int>> &moveCost, int &r, int &c, int &ans)
    {
        curr += val;

        if (curr_row == r-1)
        {
            ans = min(ans, curr);
            return;
        }

        vector<int> here = moveCost[val];
        for (int j = 0; j < c; j++)
        {
            help(grid[curr_row + 1][j], curr + here[j], curr_row + 1, grid, moveCost, r, c, ans);
        }
    }

    int memo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &moveCost, int &r, int &c, vector<vector<int>> &dp)
    {
        if (i == r-1)
        {
            return grid[i][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for (int k = 0; k < c; k++)
        {
            ans = min(grid[i][j] + moveCost[grid[i][j]][k] + memo(i + 1, k, grid, moveCost, r, c, dp), ans);
        }

        return dp[i][j] = ans;
    }


    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = INT_MAX;
        // for (int j = 0; j < c; j++)
        // {
        //     help(grid[0][j], 0, 0, grid, moveCost, r, c, ans);
        // }

        // return ans;

        vector<vector<int>> dp(r, vector<int> (c, -1));
        int curr = 0, curr_row = 0;
        int here = INT_MAX;
        for (int i = 0; i < c; i++)
        {
            here = min(here, memo(0,i,grid,moveCost,r,c,dp));
        }
        return here;
    }
};