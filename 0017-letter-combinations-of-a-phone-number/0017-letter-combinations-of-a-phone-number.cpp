class Solution {
public:
    void combination(string digits, string output, int index, vector<string> &ans, string mapping[]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        int num = digits[index] -'0';
        string value = mapping[num];

        for(int j = 0; j < value.length(); j++){
            output.push_back(value[j]);
            combination(digits, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        int index = 0;

        if(digits.length() == 0){
            return ans;
        }

        string mapping[10] ={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        combination(digits, output, index, ans, mapping);
        return ans;
    }
};