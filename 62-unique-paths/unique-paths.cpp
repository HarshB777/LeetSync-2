class Solution {
public:
    int xf, yf;
    void help(int x, int y, int &ans)
    {
        if (x == xf-1 && y == yf-1)
        {
            ans++;
            return;
        }
        if (x >= xf || y >= yf)
        {
            return;
        }
        help(x + 1, y, ans);
        help(x, y + 1, ans);
    }

    int memo(int x, int y, vector<vector<int>> &dp)
    {
        if (x == xf - 1 && y == yf -1)
        {
            cout<<"returning 1"<<endl;
            return 1;
        }
        if (x >= xf || y >= yf)
        {
            return 0;
        }

        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }

        int right = 0, down = 0;
        right = memo(x, y + 1, dp);
        down = memo(x + 1, y, dp);

        return dp[x][y] = right + down;
        
    }
    int uniquePaths(int m, int n) {
        int x = 0, y = 0;
        // int ans = 0;

        xf = m;
        yf = n;

        // help(x,y,ans);

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return memo(x,y,dp);
    }
};