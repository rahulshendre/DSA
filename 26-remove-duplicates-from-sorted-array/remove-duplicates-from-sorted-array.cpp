class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;  // Handle edge case if the array is empty.

        int left = 0;  // Pointer to the current position in the array.

        for(int right = 1; right < nums.size(); ++right) {
            if(nums[right] != nums[left]) {  // If current element is not equal to the last unique element
                left++;  // Move the left pointer to the next available spot
                nums[left] = nums[right];  // Update the unique element at that position
            }
        }

        return left + 1;  // The length of the array without duplicates is left + 1
    }
};
