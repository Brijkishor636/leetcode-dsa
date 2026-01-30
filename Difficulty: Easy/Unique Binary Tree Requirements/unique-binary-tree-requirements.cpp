// User function Template for C++

class Solution {
  public:
    bool isPossible(int a, int b) {
        if((a == 1 && b == 3) || (a == 3 && b == 1) || (a == 1 && b == 1) || (a == 3 && b == 3) || (a == 2 && b == 2)){
            return false;
        }
        else 
            return true;
    }
};