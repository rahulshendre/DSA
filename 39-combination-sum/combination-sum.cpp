class Solution {
    private:
    void comboSum(vector<int> &nums, vector<int> &current, int index, int target, vector<vector<int>> &result){

        if(target == 0){
            result.push_back(current);
            return;
        }

        if(target < 0 || index ==nums.size()){
            return;
        }
        comboSum(nums, current, index + 1,target, result);
        current.push_back(nums[index]);
        comboSum(nums, current, index,target - nums[index], result);
        current.pop_back();

  
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        comboSum(candidates, current, 0,target,  result);

        return result;
    }
};