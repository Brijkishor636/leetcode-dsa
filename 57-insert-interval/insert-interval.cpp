class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>>result;

        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][1] < start){
                result.push_back({intervals[i][0], intervals[i][1]});
            }
            else if(intervals[i][0] > end){
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start, end});
        return result;
    }
};