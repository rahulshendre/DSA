class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        vector<int> row_count(m, 0); // To count servers in each row
        vector<int> col_count(n, 0); // To count servers in each column

        // First pass: Count servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        // Second pass: Count servers that communicate
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // A server communicates if there is another server in the same row or column
                if (grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};
