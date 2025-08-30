class Solution {
  public:
    int floorSqrt(int n) {
        int s = 1;
        int e = n;
        int temp = 0;
        while (s <= e){
            int mid = s + (e-s)/2;
            int x = mid * mid;
            if(x == n){
                return mid;
            }
            else if(x > n){
                e = mid - 1;
            }
            else{
                temp = mid;
                s = mid + 1;
            }
        }
        return temp;
    }
};