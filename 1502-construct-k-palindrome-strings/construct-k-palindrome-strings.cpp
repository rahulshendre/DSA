class Solution {
public:
    bool canConstruct(string s, int k) {
        //frreq, then odd

        if(k > s.size()) return false;

        int freq[26] = {0};
        for(char c : s){
            freq[c - 'a']++;
        }

        int oddCount = 0;

        for(int f : freq){
            if(f % 2 != 0){
                oddCount++;
            }
        }
        return oddCount <= k;
    }
};