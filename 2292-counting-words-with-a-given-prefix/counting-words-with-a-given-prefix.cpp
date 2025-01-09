class Solution {
    bool isPrefix(string& word, string& pre){

        int len1 = word.size();
        int len2 = pre.size();

        if(len2 > len1){
            return false;
        }
        for(int i = 0; i < len2; i++){
            if(word[i] != pre[i]){
                return false;
            }
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            if(isPrefix(words[i], pref)){
                count++;
            }
        }
        return count;
    }
};