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
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int ans = 0;
        int i = 0, j = 0;
        //help(i, j, obs, ans);
        int r = obs.size();
        int c = obs[0].size();
        vector<vector<int>> dp(r, vector<int> (c,-1));
        return memo(0,0,obs,dp,r,c);
    }
};