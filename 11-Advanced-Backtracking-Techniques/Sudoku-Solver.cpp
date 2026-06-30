#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char val){
    int strow = (row/3)*3;
    int stcol = (col/3)*3;

    for(int i=0 ; i<9 ; i++){
        if(board[row][i] == val){
            return false;
        }
    }
    for(int i=0 ; i<9 ; i++){
        if(board[i][col] == val){
            return false;
        }
    }
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ;j++){
            if(board[strow+i][stcol+j] == val){
                return false;
            }
        }
    }
return true;
}

bool valid(vector<vector<char>> &board){
    for(int row=0 ; row<9 ; row++){
        for(int col=0 ; col<9 ;col++){
            if(board[row][col] == '.'){
                for(char c='1' ; c<='9' ; c++){
                    if(isSafe(board,row,col,c)){
                        board[row][col] = c;
                        if(valid(board) == true){
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
            return false;
            }
        }
    }
return true;
}
 
int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    valid(board);

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}