class Solution {
public:
vector<pair<int,int>> direction = {{1,0} , {0 ,1 } , { -1 , 0 } , {0 , -1}} ;
    int minimumEffortPath(vector<vector<int>>& heights) {
     int    n = heights.size();
        int m = heights[0].size();
 set<tuple<int,int,int>> st;

vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

dist[0][0] = 0;
st.insert({0, 0, 0});

while(!st.empty()) {

    auto it = st.begin();
    int eff = get<0>(*it);
    int x = get<1>(*it);
    int y = get<2>(*it);
    st.erase(it);
    for(auto &d : direction){
        int i = d.first ;
        int j = d.second ;
        int nx = x + i;
        int ny = y + j ;
        if(nx>= 0 && ny >=0 && nx < n && ny < m ){
             int effort = max( eff ,  abs( heights[nx][ny]  - heights[x][y]));
             if(effort < dist[nx][ny]){
                  dist[nx][ny] = effort ;
                  st.insert({effort , nx , ny}) ;
             }

        }
    }

}
return dist[n-1][m-1];
    }
};