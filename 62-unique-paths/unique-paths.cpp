class Solution {
public:
    vector<vector<int>> dp;
    int ans;

    int memo(int x, int y, int m, int n) {

        if (x == m && y == n) {
            return 1;
        }
        if (x > m || y > n) {
            return 0;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        

        return dp[x][y] = memo(x+1,y,m,n) + memo(x,y+1,m,n);
    }



    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int> (n,-1));
        dp[m-1][n-1]=1;
        
        
        return memo(0,0,m-1,n-1);
    }
};