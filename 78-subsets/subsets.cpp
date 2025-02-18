class Solution {
    private:
    void generateSubs(vector<int> &nums, vector<int> &current, int index,vector<vector<int>> &result){
        if(index == nums.size()){
          result.push_back(current);
        return ;
        }
        generateSubs(nums, current, index+1, result);
        current.push_back(nums[index]);
        generateSubs(nums, current, index+1, result);
        current.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        int index;
        generateSubs(nums, current, 0, result);

        return result;
    }
};