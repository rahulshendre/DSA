class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxSize = 0;
        int lastIndex = -1;
        vector<int> dp(n, 1), prev(n, -1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] ==0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] +1;
                    prev[i] = j;

                }
            }
            if(dp[i] > maxSize){
                maxSize = dp[i];
                lastIndex = i;
            }  
        } 
        vector<int> result;
        while(lastIndex != -1){
            result.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }


};