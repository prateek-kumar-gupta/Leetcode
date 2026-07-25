class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
     
        int count = 0 ; int j = 0 ;
        for(int i = 0  ; i < g.size() && j < s.size(); i++){
            if(g[i]<=s[j]){j++ ; count++ ; }
        }
        return count ;
    }
};