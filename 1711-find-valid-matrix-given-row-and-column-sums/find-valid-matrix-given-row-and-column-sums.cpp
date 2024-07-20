class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r = rowSum.size();
        int c = colSum.size();
        vector<vector<int>> ans(r, vector<int> (c,0));
        for (int i = 0; i < r; i++)
        {
            
            for (int j = 0; j < c; j++)
            {
                int r1 = rowSum[i];
                int c1 = colSum[j];
                

                if (rowSum[i] > 0 && colSum[j] > 0)
                {
                    int mx = min(rowSum[i],colSum[j]);
                    rowSum[i] -= mx;
                    colSum[j] -= mx;
                    ans[i][j] += mx;
                }

                
            }
        }

        return ans;
    }
};