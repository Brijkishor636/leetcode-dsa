class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle.size() > haystack.size()){
            return -1;
        }
       string str = "";
       for(int i = 0; i < (haystack.size()-needle.size()+1); i++){

            int j = 0;
            while(j < needle.size() && haystack[i+j] == needle[j]){
                str += needle[j];
                j++;
            }

            if(str == needle){
                return i;
            }
            else{
                str = "";
            }
       }

        return -1;
    }
};