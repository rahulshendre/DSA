class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns

        int low = 0;
        int high = m * n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target){
                return true;
            }

            if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;

            }
        }
        return false;
        
    }
};