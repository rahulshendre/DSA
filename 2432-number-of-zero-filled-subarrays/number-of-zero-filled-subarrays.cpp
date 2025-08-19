class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long lenght = 0;

        for(int num : nums ){
            if(num == 0){
                lenght++;
                count += lenght;
            }
            else{
                lenght = 0;
            }
        }
        return count;
    }
};