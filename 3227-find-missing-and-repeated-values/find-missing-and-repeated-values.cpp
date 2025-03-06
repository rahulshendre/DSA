class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n*m;
        unordered_map<int, int> mpp;
        vector<int> result(size);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mpp[grid[i][j]]++;
            }
        }
        int missing = -1;
        int repeated = -1;
        for(int i = 1; i <= size; i++ ){
            
            if(mpp[i] > 1){
                repeated = i;
            }
            if(mpp[i] == 0){
                    missing = i;
            }
        }
        return {repeated, missing};
    }
};