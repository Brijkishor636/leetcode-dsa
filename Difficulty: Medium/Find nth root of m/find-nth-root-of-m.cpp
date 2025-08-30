class Solution {
  public:
    int power(int mid, int n, int m){
        int result = 1;
        for(int i = 0; i < n; i++){
            result = result * mid;
            if(result > m)
                return result;
        }
        return result;
    }
    int nthRoot(int n, int m) {
        if(n == 1)
            return m;
        if(m == 0)
            return 0;
            
        int s = 1;
        int e = m;
        while(s <= e){
            int mid = s + (e-s)/2;
            int val = power(mid, n, m);
            if(val == m)
                return mid;
            else if(val > m)
                e = mid - 1;
            else 
                s = mid + 1;
        }
        return -1;
    }
};