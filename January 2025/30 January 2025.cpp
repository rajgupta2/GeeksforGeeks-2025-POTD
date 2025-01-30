/*
N-Queen Problem
The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.
Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
*/
class Solution {
  public:
  void nQueenUtil(int j, int n, vector<int> &board, vector<bool> &rows,
    vector<bool> &diag1, vector<bool> &diag2, vector<vector<int>> &res) {

    if (j > n) {
          // A solution is found
        res.push_back(board);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!rows[i] && !diag1[i + j] && !diag2[i - j + n]) {

            // Place queen
            rows[i] = diag1[i + j] = diag2[i - j + n] = true;
            board.push_back(i);

            // Recurse to the next column
            nQueenUtil(j + 1, n, board, rows, diag1, diag2, res);

            // Remove queen (backtrack)
            board.pop_back();
            rows[i] = diag1[i + j] = diag2[i - j + n] = false;
        }
    }
}
    vector<vector<int>> nQueen(int n) {

        vector<vector<int>> res;
        vector<int> board;

        // Rows occupied
        vector<bool> rows(n + 1, false);

        // Major diagonals (row + j) and Minor diagonals (row - col + n)
        vector<bool> diag1(2 * n + 1, false);
        vector<bool> diag2(2 * n + 1, false);

        // Start solving from the first column
        nQueenUtil(1, n, board, rows, diag1, diag2, res);
        return res;
    }
};