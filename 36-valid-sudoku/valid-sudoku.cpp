class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        if ((rows / 3) != (cols / 3)) {
            return false;
        }
        
        // number of individual 3*3 matrix
        int numEachMatrix = 9;


        // tracker for individual matrix as to 1-9 is visited
        vector<vector<bool>> eachMatrix(numEachMatrix, vector<bool> (10,false));

        // tracker for individual rows as to 1-9 is visited
        vector<vector<bool>> eachRow(rows, vector<bool> (10, false));

        // tracker for individual cols as to 1-9 is visited
        vector<vector<bool>> eachCol(cols, vector<bool> (10, false));

        bool ansFlag = true;
        for (int curr_row = 0; curr_row < rows; curr_row++) {
            for (int curr_col = 0; curr_col < cols; curr_col++) {
                
                int index_eachMatrix = (curr_row / 3)*3 + curr_col / 3;
                int index_eachRow = curr_row;
                int index_eachCol = curr_col;
                if (board[curr_row][curr_col] == '.') {
                    continue;
                }
                int curr_value = board[curr_row][curr_col] - '0';

                // check if curr_value is visited in eachMatrix
                if (eachMatrix[index_eachMatrix][curr_value])
                {
                    cout << "breaking for eachMatrix :: r = " << curr_row << " c = " << curr_col << " curr_val = ";
                    cout << curr_value << " bool = "<< eachMatrix[index_eachMatrix][curr_value] << endl;
                    ansFlag = false;
                    break;
                }

                // check if curr_value is visited in eachRow
                if (eachRow[index_eachRow][curr_value]){
                    cout << "breaking for eachRow :: r = " << curr_row << " c = " << curr_col << endl;
                    ansFlag = false;
                    break;
                }

                // check if curr_value is visited in eachCol
                if (eachCol[index_eachCol][curr_value]) {
                    ansFlag = false;
                    cout << "breaking for eachRow :: r = " << curr_row << " c = " << curr_col << endl;
                    break;
                }


                // if control comes here means it is not visited yet, in all possiblities. mark visited in all 3 possiblites
                eachMatrix[index_eachMatrix][curr_value] = true;
                eachRow[index_eachRow][curr_value] = true;
                eachCol[index_eachCol][curr_value] = true;
            }
            if (!ansFlag)
            {
                cout << "::::::: break call received breaking " << endl << endl;
                break;
            }
        }

        return ansFlag;
    }
};