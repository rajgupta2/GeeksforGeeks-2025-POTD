/*
Solve the Sudoku
Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.
*/
class Solution {
  public:

// Function to check if it is safe to place num at mat[row][col]
bool isSafe(vector<vector<int>> &mat, int row, int col, int num) {

    // Check if num exist in the row
    for (int x = 0; x <= 8; x++)
        if (mat[row][x] == num)
            return false;

    // Check if num exist in the col
    for (int x = 0; x <= 8; x++)
        if (mat[x][col] == num)
            return false;

    // Check if num exist in the 3x3 sub-matrix
    int startRow = row - (row % 3), startCol = col - (col % 3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve the Sudoku problem
bool solveSudokuRec(vector<vector<int>> &mat, int row, int col) {
    int n = mat.size();

    // base case: Reached nth column of last row
    if (row == n - 1 && col == n)
        return true;

    // If last column of the row go to next row
    if (col == n) {
        row++;
        col = 0;
    }

    // If cell is already occupied then move forward
    if (mat[row][col] != 0)
        return solveSudokuRec(mat, row, col + 1);

    for (int num = 1; num <= n; num++) {

        // If it is safe to place num at current position
        if (isSafe(mat, row, col, num)) {
            mat[row][col] = num;
            if (solveSudokuRec(mat, row, col + 1))
                return true;
            mat[row][col] = 0;
        }
    }

      return false;
}

void solveSudoku(vector<vector<int>> &mat) {
      solveSudokuRec(mat, 0, 0);
}
};