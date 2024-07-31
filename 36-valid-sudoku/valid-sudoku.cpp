class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        vector<vector<bool>> rows(r, vector<bool> (10,false));
        vector<vector<bool>> cols(c, vector<bool> (10,false));
        vector<vector<bool>> sub(9, vector<bool> (10,false));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int num = -1;
                if (board[i][j] != '.')
                {
                    num = board[i][j]-'0';
                }

                if (num != -1)
                {
                    if (rows[i][num])
                        return false;
                    
                    rows[i][num] = true;

                    if (cols[j][num])
                        return false;
                    cols[j][num] = true;
                    
                    int sub_idx = 0;
                    sub_idx = (i/3)*3 + j/3;
                    if (sub[sub_idx][num])
                    {
                        return false;
                    }
                    sub[sub_idx][num] = true;
                }
                //endof if
                
            }
            
        }

        return true;
    }
};