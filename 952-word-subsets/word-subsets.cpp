class Solution {
    private:
    bool isSubset(string& words, int maxFreq[26]){
        int freq[26] = {0};

        for(char c : words)
        {
            freq[c - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] < maxFreq[i]){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        int maxFreq[26] = {0};

        for(string& word :  words2){
            int freq[26] = {0};
            for(char c : word){
                freq[c - 'a']++;
                maxFreq[c - 'a'] = max(maxFreq[c - 'a'], freq[c - 'a']);
            }
        }



        vector<string> result;

        for(int i = 0; i < words1.size(); i++)
        {
            if(isSubset(words1[i], maxFreq)){
                result.push_back(words1[i]);
            }
        }
        return result;

    }
};