class Solution {
    private:
    bool isPrefixAndSuffix(string& str1, string& str2){
        int l1 = str1.size();
        int l2 = str2.size();

        if(l1 > l2){
            return false;
        }
        bool isPrefix = (str2.substr(0,l1)==str1);

        bool isSuffix = (str2.substr(l2-l1) == str1);

        return isPrefix && isSuffix; 
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};