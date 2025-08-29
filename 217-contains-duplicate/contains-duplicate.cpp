class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int num : nums){
            mpp[num]++;
        }
        for(auto num : mpp){
            if(num.second >= 2){
                return true;
            }
        }
        return false;
    }
};