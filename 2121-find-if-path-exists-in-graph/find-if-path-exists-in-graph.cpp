class Solution {
public:
    

    

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> hm;
        
        for (auto x: edges)
        {
            hm[x[0]].push_back(x[1]);
            hm[x[1]].push_back(x[0]);
        }

        //global_dest = destination;
        vector<int> vis(n, 0);
        
        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while (!q.empty())
        {
            if (vis[destination])
            {
                break;
            }

            int curr = q.front();
            q.pop();

            for (auto x: hm[curr])
            {
                if (!vis[x]){
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }



        

        
        return vis[destination];

    }
};