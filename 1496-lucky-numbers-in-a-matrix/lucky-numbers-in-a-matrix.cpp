class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> row(r,INT_MAX);
        vector<int> col(c,INT_MIN);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                row[i] = min(matrix[i][j], row[i]);
                col[j] = max(matrix[i][j], col[j]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j])
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};