// Source : https://leetcode.com/problems/set-matrix-zeroes/
// Author : Yash Agrahari
// Date   : 2024-10-20

/********************************************************************************** 
* 
* Given an `m x n` integer matrix, if an element is 0, set its entire row and column to 0's.
* You must do it in place.
* 
* Constraints:
* - `m == matrix.length`
* - `n == matrix[0].length`
* - 1 <= m, n <= 200
* - -2^31 <= matrix[i][j] <= 2^31 - 1
* 
* Example:
* 
* Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
* Output: [[1,0,1],[0,0,0],[1,0,1]]
* 
**********************************************************************************/

// Brute Force Approach
    class Solution {
    public:
        void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
            // set all non-zero elements as -1 in the row i:
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != 0) {
                    matrix[i][j] = -1;
                }
            }
        }

        void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
            // set all non-zero elements as -1 in the col j:
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] != 0) {
                    matrix[i][j] = -1;
                }
            }
        }

        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();

            // Set -1 for rows and cols that contain 0. Don't mark any 0 as -1:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        markRow(matrix, n, m, i);
                        markCol(matrix, n, m, j);
                    }
                }
            }

            // Finally, mark all -1 as 0:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == -1) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    };

    // Time Complexity: O((N*M)*(N + M)) + O(N*M) 
    // Space Complexity: O(1)


// Better Approach
    class SolutionBetter {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            vector<int> row(m, 1), col(n, 1);
            
            // Mark rows and columns that need to be set to zero
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 0) {
                        row[i] = 0;
                        col[j] = 0;
                    }
                }
            }
            
            // Set matrix elements to zero based on marked rows and columns
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (row[i] == 0 || col[j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    };

    // Time Complexity: O(2*(N*M))
    // Space Complexity: O(N) + O(M)


// Optimized Approach
    class SolutionOptimized {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();

            // int row[n] = {0}; --> matrix[..][0]
            // int col[m] = {0}; --> matrix[0][..]
            int col0 = 1;

            // Step 1: Traverse the matrix and mark the first row and column accordingly
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        if (j != 0) matrix[0][j] = 0;
                        else col0 = 0;
                    }
                }
            }

            // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }

            // Step 3: Finally mark the 1st col & then 1st row:
            if (matrix[0][0] == 0) {
                for (int j = 0; j < m; j++) {
                    matrix[0][j] = 0;
                }
            }
            if (col0 == 0) {
                for (int i = 0; i < n; i++) {
                    matrix[i][0] = 0;
                }
            }
        }
    };

    // Time Complexity: O(2*(N*M))
    // Space Complexity: O(1)
