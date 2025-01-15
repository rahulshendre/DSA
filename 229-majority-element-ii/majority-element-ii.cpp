class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> result;
        int n = nums.size();
        
        unordered_map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;
        }

        for(auto& [key, value] : mpp){
            if(value > n/3){
                result.push_back(key);
            }
        }

        return result;

    }
};