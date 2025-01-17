class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        int result = 0;
        for(auto& num : derived){
            result = result ^ num;
        }
        return result == 0;
    }
};