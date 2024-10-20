// Source: https://leetcode.com/problems/pascals-triangle/
// Author : Yash Agrahari
// Date   : 2024-10-20

/********************************************************************************** 
* 
* Given an integer numRows, return the first numRows of Pascal's triangle.
* In Pascal's triangle, each number is the sum of the two numbers directly above it.
* 
* Constraints:
* - 1 <= numRows <= 30
* 
* Example:
* 
* Input: numRows = 5
* Output: 
* [
*      [1],
*      [1,1],
*      [1,2,1],
*      [1,3,3,1],
*      [1,4,6,4,1]
* ]
**********************************************************************************/

/********************************************************************************** 
* Pascal's Triangle Problem Variations:
* 
* - Variation 1: Given row number `r` and column number `c`, print the element at position (r, c).
* - Variation 2: Given row number `n`, print the `n-th` row of Pascal's triangle.
* - Variation 3: Given the number of rows `n`, print the first `n` rows of Pascal's triangle.
**********************************************************************************/

// Function to calculate nCr using formula: nCr = n! / (r! * (n-r)!)
    int nCr(int n, int r) {
        long long res = 1;
        // Calculating nCr in a loop to avoid large intermediate factorials:
        for (int i = 0; i < r; i++) {
            res = res * (n - i);   // Multiply numerator
            res = res / (i + 1);   // Divide by denominator
        }
        return res;
    }

// Variation 1: Given row `r` and column `c`, print the element at position (r, c)
    class Variation1 {
    public:
        // Function to return the element at row r and column c in Pascal's triangle
        int pascalTriangle(int r, int c) {
            // r - 1 and c - 1 as Pascal's triangle is 0-indexed
            return nCr(r - 1, c - 1);
        }
    };

    // Time Complexity: O(r)
    // Space Complexity: O(1)

// Variation 2: Given the row number `n`, print the `n-th` row of Pascal's triangle
    class Variation2 {
    public:
        // Naive approach
        void pascalTriangleNaive(int n) {
            for (int c = 1; c <= n; c++) {
                cout << nCr(n - 1, c - 1) << " ";  // print each element in the row
            }
            cout << endl;
        }

        // Optimized approach
        void pascalTriangleOptimized(int n) {
            long long ans = 1;
            cout << ans << " "; // print the first element
            for (int i = 1; i < n; i++) {
                // Use previous value to calculate the next value
                ans = ans * (n - i);
                ans = ans / i;
                cout << ans << " ";
            }
            cout << endl;
        }
    };

    // Time Complexity (both approaches): O(n)
    // Space Complexity (both approaches): O(1)

// Variation 3: Given the number of rows `n`, print the first `n` rows of Pascal's triangle
    class Variation3 {
    public:
        // Naive approach to generate the entire triangle
        vector<vector<int>> pascalTriangleNaive(int n) {
            vector<vector<int>> ans;
            for (int row = 1; row <= n; row++) {
                vector<int> tempRow; // Temporary row
                for (int col = 1; col <= row; col++) {
                    // Add each element at position (row, col)
                    tempRow.push_back(nCr(row - 1, col - 1));
                }
                ans.push_back(tempRow);
            }
            return ans;
        }

        // Optimized approach to generate the entire row of triangle
        vector<int> generateRow(int row) {
            long long ans = 1;
            vector<int> ansRow;
            ansRow.push_back(1);  // First element of each row is always 1
            for (int col = 1; col < row; col++) {
                // Generate next element using the previous one
                ans = ans * (row - col);
                ans = ans / col;
                ansRow.push_back(ans);
            }
            return ansRow;
        }

        // Optimized approach to generate the entire Pascal's triangle up to `n` rows
        vector<vector<int>> pascalTriangleOptimized(int n) {
            vector<vector<int>> ans;
            for (int row = 1; row <= n; row++) {
                ans.push_back(generateRow(row));  // Generate each row using the helper function
            }
            return ans;
        }
    };

    // Time Complexity (both approaches): O(n^2)
    // Space Complexity (both approaches): O(n^2)
    // Optimized approach uses O(n) space and O(n) time per row