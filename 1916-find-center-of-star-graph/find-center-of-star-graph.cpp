class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>> hm;
        int max_node = 0;
        for (auto x: edges)
        {
            max_node = max({x[0], x[1], max_node});
            hm[x[0]].push_back(x[1]);
            hm[x[1]].push_back(x[0]);
        }

       
        int ans = -1;
        for (int i = 1; i <= max_node; i++)
        {
            if (hm[i].size() == max_node-1)
            {
                ans = i;
                break;
            }
        }


        return ans;    
    }


};