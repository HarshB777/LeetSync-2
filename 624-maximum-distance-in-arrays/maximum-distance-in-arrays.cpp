class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>> maxi;
        priority_queue<pair<int,int>> mini;

        int idx = 0;
        for (auto x: arrays)
        {
            maxi.push({x.back(), idx});
            mini.push({-x.front(), idx});
            idx++;
        }

        int ans = INT_MIN;
        while (true)
        {
            int max_ele = maxi.top().first;
            int max_idx = maxi.top().second;
            maxi.pop();

            int min_ele = -mini.top().first;
            int min_idx = mini.top().second;
            mini.pop();

            if (max_idx != min_idx)
            {
                ans = max(ans, max_ele - min_ele);
            }
            else
            {
                int op1 = max_ele + mini.top().first;
                int op2 = maxi.top().first - min_ele;

                ans = max({ans, op1, op2});
            }
            break;
        }

        return ans;


    }
};