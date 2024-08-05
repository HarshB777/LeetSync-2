class Solution {
public:
    void help(int i, int j, vector<vector<int>> obs, int &ans)
    {

        if (i == obs.size()-1 && j == obs[0].size()-1)
        {
            ans++;
        }

        if (i == obs.size() || j == obs[0].size())
        {
            return;
        }

        if (obs[i][j] == 1)
        {
            return;
        }

        //move down
        help(i+1,j,obs,ans);

        //move to the right
        help(i,j+1,obs,ans);

    }

    int memo(int i, int j, vector<vector<int>> obs, vector<vector<int>> &dp, int r, int c)
    {

        if (i == r || j == c)
        {
            return 0;
        }
        

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (i == r-1 && j == c-1)
        {
            if (obs[i][j] == 0)
                return 1;
            else
                return 0;
        }

        if (obs[i][j] == 1)
        {
            return 0;
        }
        //move down
        int m1 = memo(i+1,j,obs,dp,r,c);


        //move to the right
        int m2 = memo(i, j+1, obs, dp, r, c);


        return dp[i][j] = m1+m2;


    }




long long int tab(vector<vector<int>> obs) {
    int r = obs.size();
    int c = obs[0].size();

    vector<vector<long long int>> dp(r+1, vector<long long int> (c+1, 0));

    if (obs[r-1][c-1] == 0) {
        dp[r-1][c-1] = 1;
    } else {
        return 0;
    }

    for (int i = r-1; i >= 0; i--) {
        for (int j = c-1; j >= 0; j--) {
            if (obs[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] += dp[i+1][j] + dp[i][j+1];
            }
        }
    }

    return dp[0][0];
}

    int ttab(vector<vector<int>> obs)
    {
        int r = obs.size();
        int c = obs[0].size();

        vector<vector<int>> dp(r+1, vector<int> (c+1,0));
        if (obs[r-1][c-1] == 0)
        {
            dp[r-1][c-1] = 1;
        }
        else
        {
            return 0;
        }
        for (int i = r-1; i >= 0; i--)
        {
            for (int j = c-1; j >= 0; j--)
            {
                if (obs[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] += dp[i+1][j] + dp[i][j+1];
                }

            }
        }


        return dp[0][0];

    }



    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int ans = 0;
        int i = 0, j = 0;
        //help(i, j, obs, ans);
        int r = obs.size();
        int c = obs[0].size();
        vector<vector<int>> dp(r, vector<int> (c,-1));
        //return memo(0,0,obs,dp,r,c);
        return int(tab(obs));
    }
};