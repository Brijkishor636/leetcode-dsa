class Solution {
public:

    void merge(vector<int> &arr, int s, int e){
    
    int mid = (s+e)/2;

    int n1 = mid-s+1;
    int n2 = e-mid;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    int k = s;
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[k++];
    }

    int i = 0;
    int j = 0;
    k = s;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
        
    }

    while (i < n1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr[k++] = arr2[j++];
    }
    
    delete []arr1;
    delete []arr2;
    
}

void mergeSort(vector<int> &arr, int s, int e){

    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};