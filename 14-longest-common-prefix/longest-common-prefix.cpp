class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty() == true){
            return "";
        }

        string result = "";

        for(int i = 0; i < strs[0].size(); i++){
            char currentChar = strs[0][i];
            
            for(int j = 1; j < strs.size(); j++){
                if( i >= strs[j].size() || strs[j][i] != currentChar){
                    return result;
                }
            }
            result += currentChar;
        }
        return result;
    }
};