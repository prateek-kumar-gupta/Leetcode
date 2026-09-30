class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
       vector<vector<int>>directions = {{0 ,1}, {0 ,-1}, {1 , 0}, {-1 ,0}};
        queue<pair<int,int>>que;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0 ;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty()){
        auto p = que.front();
        que.pop();
        int i = p.first ;
        int j = p.second;
        for( auto &dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni >= 0 && ni < n && nj >=0 && nj < m && ans[ni][nj] == -1 ){
            ans[ni][nj] = ans[i][j] + 1;
            que.push({ni , nj});
            }
        }
        }
        return ans ;
    }
};