class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        
        for (int r=0; r<9;r++) {
            for (int c=0; c<9; c++){
                int val = board[r][c];

                if (val == '.'){
                    continue;
                }

                //Rows
                if (rows[r].count(val) != 0) {
                    return false;
                }
                rows[r].insert(val);

                //Columns
                if (cols[c].count(val) != 0){
                    return false;
                }
                cols[c].insert(val);

                //boxes
                int box = (r/3) * 3 + c/3;
                
                if (boxes[box].count(val)){
                    return false;
                }
                boxes[box].insert(val);

            }

        }

        return true;
    }
};
