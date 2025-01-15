class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // arrays whose sum equals k
        // generate all subarrays and thier sum, and return number of arrays whose sum 
        // is greater than k 
        // int count = 0;
        // int n = nums.size();

        // for(int i = 0; i < nums.size(); i++){
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); j++){
        //         sum = sum + nums[j];
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        unordered_map<int, int> prefixSumCount = {{0,1}};
        int currentSum = 0;
        int count = 0;

        for(int num : nums)
        {
            currentSum = currentSum + num;
            count = count + prefixSumCount[currentSum - k];
            prefixSumCount[currentSum]++;
        }
        return count;
    }
};