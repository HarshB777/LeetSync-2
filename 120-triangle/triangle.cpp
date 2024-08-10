class Solution {
public:
    void help(int i, int j, int curr, vector<vector<int>> tri, int &ans)
    {

        if (i == tri.size())
        {
            ans = min(ans, curr);
            return;
        }


        help(i+1,j,curr+tri[i][j],tri, ans);

        if (i != tri.size()-1)
        {
            if ((j+1) != tri[i+1].size())
            {
                help(i+1,j+1,curr+tri[i][j],tri,ans);
            }
        }

    }

    int memo(int i, int j, vector<vector<int>> grid, vector<vector<int>> &dp)
    {
        vector<vector<int>> tri = grid;
        if (i == tri.size())
        {
            return 0;
        }

        if (j >= tri[i].size())
        {
            return INT_MAX;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int down = grid[i][j] + memo(i+1, j, tri, dp);

        int right = grid[i][j] + memo(i+1, j+1, tri,dp);


        return dp[i][j] = min(down, right);
        
    }

    int tab(vector<vector<int>> tri)
    {

        int r = tri.size();
        int c = r;

        if (r == 1)
        {
            return tri[0][0];
        }
        vector<vector<int>> dp(r, vector<int> (c,0));


        for (int i = 0; i < r; i++)
        {
            dp[r-1][i] = tri[r-1][i];
        }
        cout<<"after filling of last row"<<endl;
        for (auto x: dp)
        {
            for (auto y: x)
            {
                cout<<y<<" ";
            }
            cout<<endl;
        }


        for (int i = r-2; i >= 0; i--)
        {
            for (int j = 0; j < (i+1); j++)
            {
                int op1 = INT_MAX, op2 = INT_MAX;
                
                
                op2 = tri[i][j] + dp[i+1][j+1];
                
                op1 = tri[i][j] + dp[i+1][j];


                dp[i][j] = min(op1, op2);
            }
        }
        
        cout<<"ultimate"<<endl;
        for (auto x: dp)
        {
            for (auto y: x)
            {
                cout<<y<<" ";
            }
            cout<<endl;
        }


        return dp[0][0];

    }



    int minimumTotal(vector<vector<int>>& triangle) {
        int i = 0, j = 0;
        int ans = INT_MAX;
        int curr = 0;

        //help(i,j,curr,triangle,ans);
        int n = triangle.size();
        int m = pow(n,2);
        //vector<vector<int>> dp(n, vector<int> (n, -1));

        //return ans;

        //return memo(0,0,triangle,dp);
        return tab(triangle);

    }
};