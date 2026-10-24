class Solution {
public:
    #define p pair<int,int>
    #define t tuple<int , int  , int >
    vector<p> direction = { {1 , 0 } , {-1 , 0} , {0 , 1 }, {0 , -1}} ;
    int swimInWater(vector<vector<int>>& grid) {
        int  n = grid.size();
        set<t> st ;
        int ans  = grid[0][0];
        st.insert({ans  , 0 ,0});
        grid[0][0] = -1 ;
        while(!st.empty()){
            auto it = st.begin();
            int x = get<1>(*it);
            int y = get<2>(*it);
            int ct = get<0>(*it);
            st.erase(it);
            if(x == n-1 && y== n-1 ){
                ans  = ct ;
            }
            for(auto &a : direction){
                int nx = x + a.first ;
                int ny = y + a.second ;
                if(nx>=0 && nx<n && ny >= 0 && ny < n && grid[nx][ny] != -1 ){
                        int time = grid[nx][ny];
                        grid[nx][ny] = -1 ;
                        if(time > ct){
                            st.insert({time , nx , ny});
                        }
                        else st.insert({ct , nx , ny});
                }
                
            }
        }
        return ans  ;
    }
};