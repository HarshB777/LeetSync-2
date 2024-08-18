class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> vis(r, vector<int> (c,0));
        vector<vector<int>> ans(r, vector<int> (c,0));
        queue<pair<pair<int,int>,int>> q;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<int> drow = {1,-1,0,0};
        vector<int> dcol = {0,0,1,-1};

        while (!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int cdist = q.front().second;

            
            ans[i][j] = cdist;

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int ci = i + drow[k];
                int cj = j + dcol[k];


                if (ci >= 0 && ci < r && cj >= 0 && cj < c && vis[ci][cj] == 0)
                {
                    q.push({{ci,cj},cdist+1});
                    vis[ci][cj] = 1;
                }
            }
        }


        return ans;


    }
};