class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        map<int, int> mpp;

        int l = 0;
        int r = 0;
        int n = fruits.size();
        int max_len = 0;

        for(int r = 0 ; r < n; r++){
            mpp[fruits[r]]++;

            while(mpp.size() > 2){
                mpp[fruits[l]]--;

                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            max_len = max(max_len, r-l+1);
        }
        return max_len;
    }
};