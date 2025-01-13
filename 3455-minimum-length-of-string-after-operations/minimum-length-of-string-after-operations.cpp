class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {0};
        for (char& c : s) {
            freq[c - 'a']++;
        }
        int ans = 0;
        for (int x : freq) {
            if (x) {
                ans += x % 2 ? 1 : 2;
            }
        }
        return ans;
    }
};