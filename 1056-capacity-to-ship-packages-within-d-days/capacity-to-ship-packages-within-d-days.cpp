class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        long long sum = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }
        if(days == 1){
            return sum;
        }
        int s = maxi;
        int e = sum;
        int result = 0;
        while(s <= e){
            int mid = s + (e-s)/2;
            int prefix = 0;
            int count = 1;
            for(int i = 0; i < weights.size(); i++){
                if(prefix + weights[i] > mid){
                    count++;
                    prefix = 0;
                }
                prefix += weights[i];
            }
            if(count <= days){
                result = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
         return result;
    }
};