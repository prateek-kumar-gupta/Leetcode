class Solution {
public:

    bool possible(vector<vector<char>>& board, char k, int a, int b) {

        // row
        for(int j = 0; j < 9; j++) {
            if(board[a][j] == k)
                return false;
        }

        // column
        for(int i = 0; i < 9; i++) {
            if(board[i][b] == k)
                return false;
        }

        // 3 x 3 box
        int row = (a / 3) * 3;
        int col = (b / 3) * 3;

        for(int i = row; i < row + 3; i++) {
            for(int j = col; j < col + 3; j++) {
                if(board[i][j] == k)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {

                    for(char k = '1'; k <= '9'; k++) {

                        if(possible(board, k, i, j)) {

                            board[i][j] = k;

                            if(solve(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};