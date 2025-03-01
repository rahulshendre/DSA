class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Apply operations
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;   // Multiply nums[i] by 2
                nums[i + 1] = 0; // Set nums[i + 1] to 0
            }
        }

        // Step 2: Shift zeros to the end
        vector<int> result;
        for (int num : nums) {
            if (num != 0) {
                result.push_back(num); // Add non-zero elements
            }
        }

        // Fill the rest with zeros
        while (result.size() < n) {
            result.push_back(0);
        }

        return result;
    }
};
