class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums; // return sorted array
    }

private:
    // Merge two sorted halves into one sorted array
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left;     // pointer for left half
        int j = mid + 1;  // pointer for right half

        // Compare elements from both halves and pick smaller
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) 
                temp.push_back(arr[i++]);
            else 
                temp.push_back(arr[j++]);
        }

        // Add remaining elements from left half
        while (i <= mid) temp.push_back(arr[i++]);

        // Add remaining elements from right half
        while (j <= right) temp.push_back(arr[j++]);

        // Copy sorted elements back to original array
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }

    // Recursive function to divide array into halves
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;  // base case: single element
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // sort left half
        mergeSort(arr, mid + 1, right);  // sort right half
        merge(arr, left, mid, right);    // merge both halves
    }
};
