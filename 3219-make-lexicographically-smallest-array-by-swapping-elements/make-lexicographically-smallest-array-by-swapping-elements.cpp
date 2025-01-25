class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        std::vector<std::deque<int>> groups;
        std::unordered_map<int, int> numToGroup;

        // Sort the numbers to process in order
        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());

        // Form groups based on the threshold limit
        for (int n : sortedNums) {
            if (groups.empty() || abs(n - groups.back().back()) > limit) {
                groups.push_back(std::deque<int>());
            }
            groups.back().push_back(n);
            numToGroup[n] = groups.size() - 1;
        }

        // Construct the result by assigning each original index
        std::vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int groupIndex = numToGroup[nums[i]];
            result[i] = groups[groupIndex].front();
            groups[groupIndex].pop_front();
        }

        return result;
    }
};
