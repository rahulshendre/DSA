class Solution {
public:
    int total = 0;

    void help(vector<int>& nums, int i, int xor_val){
        if(i == nums.size()){
            total += xor_val;
            return;
        }

        help(nums, i+1, xor_val^nums[i]);
        help(nums, i+1, xor_val);
    }

    int subsetXORSum(vector<int>& nums) {
        help(nums, 0,0);
        return total;
    }
};