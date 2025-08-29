class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(2);

        int find;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(target == nums[i] + nums[j]){
                    return {i,j};
                }

            }
        }
        return {};
    }
};