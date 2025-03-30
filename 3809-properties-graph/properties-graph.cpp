class Solution {
public:
    int rows;
    vector<unordered_set<int>> num_idx_map;
    vector<unordered_set<int>> num_map;
    vector<vector<int>> prop;
    int limit;
    vector<unordered_set<int>> adj;

    void constructGraph() {
        rows = prop.size();
        num_idx_map.resize(101);
        num_map.resize(rows);
        adj.resize(rows);


        for (int i = 0; i < rows; i++) {
            vector<int> arr = prop[i];

            for (int val : arr)
            {
                num_idx_map[val].insert(i);
                num_map[i].insert(val);
            }
        }


        for (int i = 0; i < rows; i++)
        {
            unordered_map<int,int> idx_tracker;
            for (auto val : num_map[i]) {
                for (auto idx : num_idx_map[val])
                {
                    if (idx != i)
                    {
                        idx_tracker[idx]++;
                    }
                }
            }

            for (auto idx_tracker_itr : idx_tracker) {
                int idx = idx_tracker_itr.first, cnt = idx_tracker_itr.second;

                if (cnt >= limit) {
                    adj[i].insert(idx);
                    adj[idx].insert(i);
                }
            }
        }

    }

    void displayGraph() {
        for (int i = 0; i < rows; i++) {
            cout << "for ele : "<<i <<" adj :: ";

            for (auto x: adj[i])
            {
                cout << x << " ";
            }
            cout<<endl<<endl;
        }
    }

    void bfs(int idx, vector<bool> &vis) {
        vis[idx] = true;

        for (auto conn : adj[idx]) {
            if (!vis[conn]) {
                bfs(conn, vis);
            }
        }
    }

    int connectedComponents() {
        vector<bool> vis(rows, false);
        int cnt = 0;


        for (int i = 0; i < rows; i++) {
            if (!vis[i]){
                bfs(i, vis);
                cnt++;
            }
        }

        return cnt;

    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        prop = properties;
        limit = k;
        constructGraph();
        return connectedComponents();


        
    }
};