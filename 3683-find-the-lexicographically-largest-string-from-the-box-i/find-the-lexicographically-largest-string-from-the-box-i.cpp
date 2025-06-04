class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;

        string result = "";
        for(int i = 0; i < word.size(); i++){
            result = max(result, word.substr(i, word.length() - numFriends + 1)); 
        } 
        return result;
    }
};