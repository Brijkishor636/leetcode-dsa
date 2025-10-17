class Solution {
public:
    void generate(vector<string>&result, string str, int n, int openN, int closeN){
        if(openN == n && closeN == n){
            result.push_back(str);
            return ;
        }
        if(openN < n){
            generate(result, str+"(", n, openN+1, closeN);
        }
        if(closeN < openN){
            generate(result, str+")", n, openN, closeN+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        generate(result, "", n, 0, 0);
        return result;
    }
};