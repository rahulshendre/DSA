class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int nCount = 0;
        int pCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                pCount++;
            }
            if(nums[i] < 0){
                nCount++;
            }
        }
        int maxi = max(pCount, nCount);
        return maxi;
    }
};