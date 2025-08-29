class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int y = 2*n;

        vector<int> ans = {};

        
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
        }
        
        return ans;
    }
};