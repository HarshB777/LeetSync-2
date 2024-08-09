class Solution {
public:

    void help(int i, int j, int curr, int r, int c, vector<vector<int>> grid, int &ans)
    {   

        if (i == r-1 && j == c-1)
        {
            curr += grid[i][j];
            ans = min(ans, curr);
            return;
        }
        
        if ((i+1) < r)
            help(i+1,j,curr+grid[i][j],r,c,grid,ans);

        if ((j+1) < c)
            help(i, j+1, curr+grid[i][j], r, c, grid, ans);
        
    }


    int memo(int i, int j, int r, int c, vector<vector<int>> grid, vector<vector<int>> &dp)
    {

        if (i == r-1 && j == c-1)
        {
            return grid[i][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = INT_MAX;
        if ((i+1) < r)
            down = grid[i][j] + memo(i+1,j,r,c,grid,dp);

        int right = INT_MAX;
        if ((j+1) < c)
            right = grid[i][j] + memo(i,j+1,r,c,grid,dp);


        return dp[i][j] = min(down, right);


    }


    int tab(vector<vector<int>> grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> dp(r+1, vector<int> (c+1,INT_MAX-1000));

        dp[r-1][c-1] = grid[r-1][c-1];


        for (int i = r-1; i >= 0; i--)
        {
            for (int j = c-1; j >= 0; j--)
            {
                if (i == r-1 && j == c-1)
                {
                    continue;
                }
                int down = grid[i][j] + dp[i+1][j];
                int up = grid[i][j] + dp[i][j+1];

                dp[i][j] = min(up,down);
            }
        }


        return dp[0][0];




    }



    int minPathSum(vector<vector<int>>& grid) {
        /*
        
        *************Recursive Solution****************
        int i = 0, j = 0, curr = 0;
        int r = grid.size();
        int c = grid[0].size();
        int ans = INT_MAX;

        help(i,j,curr,r,c,grid,ans);

        return ans;
        */
        int r = grid.size();
        int c = grid[0].size();

        /*
        vector<vector<int>> dp(r, vector<int> (c,-1));
        int i = 0, j = 0;
        return memo(i,j,r,c,grid,dp);
        *********MEMOIZATION TLE***&*******
        */


        return tab(grid);

    }
};