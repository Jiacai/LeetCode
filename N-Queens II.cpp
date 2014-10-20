#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int num = 0;
    int count = 0;
    
    int totalNQueens(int n) {
        num = n;
        count = 0;
        vector<int> board(num);
        totalNQueensRe(board, 0);
        return count;
    }
    
    bool valid(vector<int> &board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || abs(board[i] - col) == row - i) {
                return false;
            }
        }
        return true;
    }
    
    void totalNQueensRe(vector<int> &board, int row) {
        if (row == num) {
            count++;
            return;
        }
        for (int i = 0; i < num; i++) {
            board[row] = i;
            if (valid(board, row, i)) {
                totalNQueensRe(board, row + 1);
            }
        }
    }
};
