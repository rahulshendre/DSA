class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        unordered_map<int, int> mpp;

        for(auto& num : nums1){
            mpp[num[0]] += num[1];
        }
        for(auto& num : nums2){
            mpp[num[0]] += num[1];
        }   

        vector<vector<int>> result;
        for(auto& [id, value] : mpp){
            result.push_back({id, value});            
        }        
        sort(result.begin(), result.end());

        return result;
    }
};