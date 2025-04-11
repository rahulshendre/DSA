class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0; // To count symmetric integers
        
        for (int i = low; i <= high; i++) {
            string num = to_string(i); // Convert integer to string
            
            if (num.length() % 2 != 0) {
                continue; // Skip numbers with odd lengths
            }
            
            int mid = num.length() / 2;
            int leftSum = 0, rightSum = 0;

            // Calculate the sum of digits for both halves
            for (int j = 0; j < mid; j++) {
                leftSum += num[j] - '0'; // Convert char to int
                rightSum += num[j + mid] - '0';
            }

            if (leftSum == rightSum) {
                count++; // Increment count if symmetric
            }
        }

        return count; // Return the final count
    }
};
