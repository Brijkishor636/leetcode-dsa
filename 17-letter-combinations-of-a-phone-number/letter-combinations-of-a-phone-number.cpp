class Solution {
private: 
    void solve(string digits, vector<string>&ans, string output, string mapping[], int index){
        if(index == digits.size()){
            ans.push_back(output);
            return ;
        }

        int value = digits[index] - '0';
        string element = mapping[value];
        for(int i = 0; i < element.size(); i++){
            output.push_back(element[i]);
            solve(digits, ans, output, mapping, index+1);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        string output;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, output, mapping, 0);
        return ans;
    }
};