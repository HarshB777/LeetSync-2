class Solution {
public:
    
    void dfs(int src, vector<vector<int>> graph, int n, vector<int> path, vector<vector<int>> &ans, vector<int> &vis)
    {
        path.push_back(src);
        
        if (src == n-1)
        {
            
            ans.push_back(path);
        
            return;
        }

        for (auto x: graph[src])
        {
            
            
            dfs(x,graph,n,path,ans,vis);
            
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> ans;
        
        vector<int> vis(n,0);
        dfs(0,graph,n,path,ans,vis);

        return ans;
    }
};