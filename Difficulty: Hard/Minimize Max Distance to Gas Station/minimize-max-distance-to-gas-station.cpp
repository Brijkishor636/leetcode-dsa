class Solution {
  public:
    bool check(vector<int>&stations, double mid, int k){
        int count=0;
      for(int i=1;i<stations.size();i++){
          int diff=stations[i]-stations[i-1];
          if(diff>mid){
              count+=diff/mid;
          }
      }
      if(count>k){
          return false;
      }
      return true;
    }
    
    double minMaxDist(vector<int> &stations, int k) {
         double start=0;
     int n=stations.size();
     double end=stations[n-1]-stations[0];
      double result=0;
     while(start<=end){
         double mid=start+(end-start)/2;
         if(check(stations,mid,k)==true){
             result=mid;
             end=mid-0.000001;
         }
         else{
             start=mid+0.000001;
         }
     }
        return result;
    }
};