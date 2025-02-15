class Solution {
    private:
    bool isSquareValid(int x, string square, int target, int currentSum, int index) {
        // Base case: if we reach the end of the square string
        if (index == square.size()) {
            return currentSum == target;
        }

        // Try all possible splits
        int num = 0;
        for (int i = index; i < square.size(); i++) {
            num = num * 10 + (square[i] - '0'); // Create the number
            if (isSquareValid(x, square, target, currentSum + num, i + 1)) {
                return true;
            }
        }

        return false;
    }

public:
    int punishmentNumber(int n) {
        int totalSum = 0;

        for (int x = 1; x <= n; x++) {
            int square = x * x;
            string squareStr = to_string(square);

            // Check if the square is valid
            if (isSquareValid(x, squareStr, x, 0, 0)) {
                totalSum += square;
            }
        }

        return totalSum;
    }
};