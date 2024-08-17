class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int r = image.size();
        int c = image[0].size();

        vector<vector<int>> vis(r, vector<int> (c,-1));
        vis[sr][sc] = 1;
        vector<vector<int>> ans(r, vector<int> (c,-1));
        int modi = image[sr][sc];

        ans[sr][sc] = color;

        queue<pair<int,int>> q;
        q.push({sr,sc});

        int drow[] = {1,-1,0,0};
        int dcol[] = {0,0,1,-1};

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int ci = i + drow[k];
                int cj = j + dcol[k];

                if (ci >= 0 && ci < r && cj >= 0 && cj < c && vis[ci][cj] == -1 && image[ci][cj] == modi)
                {
                    vis[ci][cj] = 1;
                    ans[ci][cj] = color;
                    q.push({ci,cj});
                }
            }

        }


        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (vis[i][j] == -1)
                {
                    ans[i][j] = image[i][j];
                }
            }
        }


        return ans;

        

    }
};