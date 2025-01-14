class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> hash(n,0);

        for(int num : nums)
        {
            if(num > 0 && num <=n){
                hash[num-1] = 1;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(hash[i] == 0){
                return i+1;
            }
        }

        return n + 1;
        
    }
};