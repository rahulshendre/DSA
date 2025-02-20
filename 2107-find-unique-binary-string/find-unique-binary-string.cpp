class Solution {
    private: 
    void backtrack(int n, string current, unordered_map<string, bool> &mpp, string &result, bool &found){
        if(found) return;

        if(current.size() == n){
            if(mpp.find(current) == mpp.end()){
                result = current;
                found = true;
            }
            return;
        }
        backtrack(n, current + '0', mpp, result,found);
        backtrack(n, current + '1', mpp, result,found);

    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, bool> mpp;
        for(const string &num :nums){
            mpp[num] = true;
        }      
        string result;
        bool found = false;
        backtrack(nums.size(), "", mpp, result, found);

        return result;
    }
};