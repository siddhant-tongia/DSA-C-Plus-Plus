#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<int>> &board, int row, int col){
    if(row < 0 || row > board.size()-1){
        return false;
    }
    if(col < 0 || col > board[0].size()-1){
        return false;
    }
    if(board[row][col] != -1){
        return false;
    }
return true;
}

bool solve (vector<vector<int>> &board, int num, int row, int col){
    int n = board.size();
    if(num == (n*n)-1){
        return true;
    }
    int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2}; 
    int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int i=0 ; i<8 ; i++){
        int nextrow = row + dr[i];
        int nextrcol = col + dc[i];
        if(isValid(board,nextrow,nextrcol)){
            board[nextrow][nextrcol] = num+1;
            if((solve(board,num+1,nextrow,nextrcol) == true)){
                return true;
            }
            board[nextrow][nextrcol] = -1;
        }
    }
return false;
}

int main() {
    int n = 5;
    vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0; 
        if (solve(board, 0, 0, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}