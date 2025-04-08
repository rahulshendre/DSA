class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        int temp;

        while(true){
            unordered_map<int, int> mpp;
            temp = 0;
            for(int num : nums){
                if(++mpp[num] == 2){
                    temp++;
                }
            }
            if(temp == 0 ) break;

            nums.erase(nums.begin(), nums.begin() + min(3, int(nums.size())));
            count++;
        }
        return count;
    }
};