class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        
        int left = 0;
        int right = n-1;

        vector<int> result(n);

        for(int num : nums){
            if(num < pivot){
                result[left++] = num;
            }
        }
        for(int num : nums){
            if(num == pivot){
                result[left++] = num;
            }
        }
        for(int num : nums){
            if(num > pivot){
                result[left++] = num;
            }
        }
        return result;
    }
};