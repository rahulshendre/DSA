class Solution {
    bool subsetSumK(int n, int k, vector<int> &nums){
        vector<bool> prev(k+1, false), cur(k+1, false);
        prev[0] = cur[0] = true;

        if (nums[0] <= k)
            prev[nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (nums[ind] <= target)
                    take = prev[target - nums[ind]];
                cur[target] = take || notTake;
            }
            prev = cur;
        }

        return prev[k];
    }

public:
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for (int num : nums) totSum += num;
        if (totSum % 2 != 0) return false;

        int target = totSum / 2;
        return subsetSumK(nums.size(), target, nums);
    }
};
