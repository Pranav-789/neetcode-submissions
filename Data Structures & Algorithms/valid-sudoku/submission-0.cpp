class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch != '.' && rows[i].count(ch) == 1) return false;
                else rows[i].insert(ch);

                if(ch != '.' && cols[j].count(ch) == 1) return false;
                else cols[j].insert(ch);

                int b = (i/3)*3 + j/3;

                if(ch != '.' && boxes[b].count(ch) == 1) return false;
                else boxes[b].insert(ch);
            }
        }
        return true;
    }
};
