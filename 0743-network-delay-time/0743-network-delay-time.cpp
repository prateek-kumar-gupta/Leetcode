class Solution {
public:
   #define p pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> adj(n + 1 );
        for(int i =  0 ; i < times.size() ; i++){
                 adj[times[i][0]].push_back({times[i][1] , times[i][2]});
        }
        set<p> st ;
        st.insert({0,k});
        vector<int> visited( n+1 , 1e9);
        visited[k] = 0 ;
        while(!st.empty()){
            auto it = st.begin();
            int d = it->first ;
            int node  = it->second ;
            st.erase(it);
            for(auto &a : adj[node]){
                int no = a.first ;
                int nd = a.second ;
                int distance = d + nd ;
                if(visited[no] > distance){
                      visited[no] = distance ;
                      st.insert({distance , no});
                }
            }
        }
        int ans = -1 ;
        for(int j  = 1 ; j < visited.size() ; j++ ){
            if(visited[j] == 1e9 ) return -1 ;
             ans = ans > visited[j] ? ans : visited[j] ;

        }
        return ans ;
    }
};