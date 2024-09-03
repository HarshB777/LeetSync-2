class Solution {
public:
    bool check(int st, vector<vector<int>> &graph, vector<int> &vis)
    {
        queue<int> q;
        q.push(st);
        vis[st] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto adj: graph[node])
            {
                if (vis[adj] == -1)
                {
                    q.push(adj);
                    vis[adj] = !vis[node];
                }
                else if (vis[adj] == vis[node])
                {
                    return false;
                }
            }
        }

        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                if (!check(i,graph,vis))
                {
                    return false;
                }
            }
        }

        return true;
    }
};