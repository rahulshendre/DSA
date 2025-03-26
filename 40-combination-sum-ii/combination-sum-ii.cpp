class Solution {
private:
    void generateSubs(vector<int>& nums, vector<int>& current, int index, int target, vector<vector<int>>& result) {
        // If target is met, add the current subset to the result
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Iterate through the candidates starting from the current index
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            // If the current number exceeds the target, stop further processing
            if (nums[i] > target) break;

            // Include the current number in the subset
            current.push_back(nums[i]);

            // Recur with the next index and reduced target
            generateSubs(nums, current, i + 1, target - nums[i], result);

            // Backtrack by removing the current number
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;

        // Sort the candidates to handle duplicates and optimize processing
        sort(candidates.begin(), candidates.end());

        generateSubs(candidates, current, 0, target, result);

        return result;
    }
};
