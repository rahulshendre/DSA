class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int total = 0;
        map<char, int> mpp;
        
        for(int r = 0; r < s.size(); r++){
            mpp[s[r]]++;

            while(mpp['a'] > 0 && mpp['b'] > 0 && mpp['c']){
                total += s.size() - r;
            mpp[s[left]]--;
            left++;
            }
        }
        return total;
    }
};