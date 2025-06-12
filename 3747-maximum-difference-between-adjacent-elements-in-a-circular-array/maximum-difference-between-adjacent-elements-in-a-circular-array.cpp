class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int max_elem = abs(nums[0] - nums[n-1]);
        for(int i = 0; i < n - 1; i++){
            max_elem = max(max_elem, abs(nums[i] - nums[i+1]));
        }
        return max_elem;
    }
};