class Solution {
public:
    bool isOneBitCharacter(vector<int>& b) {
        bool c;
        for (int i = 0; i < b.size();) {
            if (b[i]) c = 0, i+=2;
            else c = 1, ++i;
        }
        return c;
    }
};