class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int maxi = 0;
        for(int i = 0; i < piles.size(); i++){
            sum = sum + piles[i];
            maxi = max(piles[i], maxi);
        }
        int result = 0;
        int s = sum / h;
        int e = maxi;
        if(!s){
            s = 1;
        }
        while(s <= e){
            int mid = s + (e-s)/2;
            int time = 0;
            for(int i = 0; i < piles.size(); i++){
                time = time + piles[i]/mid;
                if(piles[i] % mid){
                    time++;
                }
            }
            if(time > h){
                s = mid + 1;
            }
            else{
                result = mid;
                e = mid - 1;
            }
        }
        return result;
    }
};