class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> topPrefix(n, 0), bottomPrefix(n, 0);

        // Calculate prefix sums for both rows
        topPrefix[0] = grid[0][0];
        bottomPrefix[0] = grid[1][0];
        for (int i = 1; i < n; ++i) {
            topPrefix[i] = topPrefix[i - 1] + grid[0][i];
            bottomPrefix[i] = bottomPrefix[i - 1] + grid[1][i];
        }

        long long result = LLONG_MAX;

        // Iterate over each column and calculate the score for Robot 2
        for (int i = 0; i < n; ++i) {
            // Top sum: cells in the top row after column i
            long long topSum = topPrefix[n - 1] - topPrefix[i];

            // Bottom sum: cells in the bottom row before column i
            long long bottomSum = (i > 0) ? bottomPrefix[i - 1] : 0;

            // Max score Robot 2 can get if Robot 1 switches at column i
            long long scoreForRobot2 = max(topSum, bottomSum);

            // Minimize the maximum score Robot 2 can get
            result = min(result, scoreForRobot2);
        }

        return result;
    }
};
