class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char>rowSet;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(rowSet.find(board[i][j])!=rowSet.end())return false;
                rowSet.insert(board[i][j]);
            }
        }
        for(int j=0;j<9;j++){
            unordered_set<char>colSet;
            for(int i=0;i<9;i++){
                if(board[i][j]=='.')continue;
                if(colSet.find(board[i][j])!=colSet.end())return false;
                colSet.insert(board[i][j]);
            }
        }
        for(int boxRow=0;boxRow<3;boxRow++){
            for(int boxCol=0;boxCol<3;boxCol++){
                unordered_set<char>boxSet;
                for(int i=boxRow*3;i<boxRow*3+3;i++){
                    for(int j=boxCol*3;j<boxCol*3+3;j++){
                        if(board[i][j]=='.')continue;
                        if(boxSet.find(board[i][j])!=boxSet.end())return false;
                        boxSet.insert(board[i][j]);
                    }
                }
                
            }
        }
        return true;
    }
};
