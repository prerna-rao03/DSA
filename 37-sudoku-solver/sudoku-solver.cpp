class Solution {
public:
    bool is_safe( int row, int col, int val,vector<vector<char>>& board ){
       
        for(int i=0; i<9; i++){
            // row check
            if(board[i][col]== val){
                return false;
            }
            // column check
            if(board[row][i]== val){
                return false;
            }
            // check 3 x 3 matrix
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3]== val){
                return false;
            }
        }
        return true; // for fully filled board
    }

    bool solve (vector<vector<char>>& board){
        for(int i = 0; i< 9;i++){
            for(int j=0; j<9;j++){
                // check for empty space 
                if(board[i][j]== '.'){
                    // loop for insertig values 1 to 9
                    for (char  k = '1'; k <= '9' ; k++){
                        if(is_safe(i, j, k,  board )){
                            // insert that value
                            board[i][j] = k;
                            // recursive call
                            bool more_solutions = solve(board);
                            if(more_solutions){
                                return true;
                            }
                            // backtrack
                            else board[i][j]='.';
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