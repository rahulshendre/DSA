class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        int count = 0;
        vector<int> result(n);

        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++)
        {
            if(++mpp[A[i]] == 2){
                count++;
            }
            if(++mpp[B[i]] ==2){
                count++;
            }
            result[i] = count;
        }
        return result;
    }  
};