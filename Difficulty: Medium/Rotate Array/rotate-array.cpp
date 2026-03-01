class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        vector<int>a;
        vector<int>b;
        int n = arr.size();
        d = d % n;
        for(int i = 0; i < d; i++){
            a.push_back(arr[i]);
        }
        for(int i = d; i < arr.size(); i++){
            b.push_back(arr[i]);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        arr.clear();
        for(int i = 0; i < a.size(); i++){
            arr.push_back(a[i]);
        }
        for(int j = 0; j < b.size(); j++){
            arr.push_back(b[j]);
        }
        reverse(arr.begin(), arr.end());
    }
};