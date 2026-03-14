class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        vector<int>arr(26, 0);
        for(int i = 0; i < s.size(); i++){
            arr[s[i] - 'a']++;
        }
        int maxi = 0;
        char result;
        for(int i = 0; i < 26; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                result = i + 'a';
            }
        }
        return result;
    }
};