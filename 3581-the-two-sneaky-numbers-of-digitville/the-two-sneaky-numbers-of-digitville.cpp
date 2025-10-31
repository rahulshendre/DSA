class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        //all the 4 ways to do it 
        //1st - sort - O(nlogn)

        // sort(nums.begin(), nums.end());
        // vector<int> res;
        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] == nums[i-1]){
        //         res.push_back(nums[i]);
        //     }
        // }
        // return res;

        //2nd - hash map
        // unordered_map<int, int>mpp;
        // vector<int> res;
        // for(int num : nums){
        //     if(mpp.count(num)){
        //         res.push_back(num);
        //     }
        //     else{
        //         mpp[num] == 1;
        //     }
        // }
        // return res;

        //3rd - array which stores the freq 
        // vector<int> res;
        // int n = nums.size();
        // vector<int> freq(n, 0);

        // for(int num : nums){
        //     freq[num]++;
        //     if(freq[num] == 2){
        //         res.push_back(num);
        //     }
        // }
        // return res;

        //4th - xor
        int XOR = 0;
        int n = nums.size() - 2;

        for (int num : nums) XOR ^= num;
        for (int i = 0; i < n; i++) XOR ^= i;

        int diffBit = XOR & -XOR;

        int a = 0, b = 0;
        for (int num : nums) {
            if ((num & diffBit) == 0) a ^= num;
            else b ^= num;
        }
        for (int i = 0; i < n; i++) {
            if ((i & diffBit) == 0) a ^= i;
            else b ^= i;
        }
        return {a, b};
    }
};