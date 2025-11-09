class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return -1;
        int a, b, c = -1;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            a = i;
            for(int j = a+1; j < n; j++){
                if(nums[a] == nums[j]){
                    b = j;
                    break;
                }
            }
            for(int k = b+1; k < n; k++){
                if(nums[a] == nums[k]){
                    c = k;
                    break;
                }
            }
            if(a != -1 && b != -1 && c != -1){
                int p = a - b;
                if(p < 0)
                    p = p * -1;
                int q = b-c;
                if(q < 0)
                    q = q * -1;
                int r = c-a;
                if(r < 0)
                    r = r * -1;
                int ans = p+q+r;
                mini = min(mini, ans);
            }
            a = -1;
            b = -1;
            c = -1;
        }
        return (mini == INT_MAX) ? -1 : mini;
    }
};