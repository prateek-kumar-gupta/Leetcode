class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0];
        int e = newInterval[1];
        int n = intervals.size();
        vector<vector<int>>ans ;
        int i = 0 ;
        while(i<n && intervals[i][1]<s){
               ans.push_back(intervals[i]);
               i++;
        }
        while(i < n && intervals[i][0] <=e ){
            s  = min(s , intervals[i][0]);
            e = max(e , intervals[i][1]);
            i++;
        }
        ans.push_back({s,e});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans ;

    }
};