class Solution {
public:
      
    int  dfs(vector<vector<int>>& grid , int i , int j){
        int a = grid.size();
        int b = grid[0].size();
        int count = 0 ;
    if(i<0 || i >= a || j < 0 || j >=b) return 0;
    if(grid[i][j]==0)return 0;
    else{ grid[i][j] = 0; count++;} 
    return count +  dfs(grid, i-1 , j) +
     dfs(grid , i + 1, j ) + 
     dfs(grid , i , j + 1 ) +
     dfs(grid , i , j-1 );
    }
    int numEnclaves(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();
         int i = 0 ; int j = 0 ;
         int ans = 0 ;
         for(j = 0 ; j < m ; j++){
            if(grid[i][j]==1){
                dfs(grid , i , j);
            }
         }
         i = n - 1;
         for(j = 0 ; j < m ; j++){
            if(grid[i][j]==1){
                dfs(grid , i , j);
            }
         }
         j = 0 ;
         for(i = 0 ; i< n ; i++){
          if(grid[i][j]==1){
                dfs(grid , i , j);
            }
         }
         j = m - 1; 
         for(i = 0 ; i< n ; i++){
          if(grid[i][j]==1){
                dfs(grid , i , j);
            }
         }
         for(int i = 1 ; i < n -1  ; i++){
            for(int j = 1 ; j < m-1 ; j++ ){
                if(grid[i][j] == 1){
                    ans = ans + 
                    dfs(grid , i , j);
                }
            }
         }
       return ans ;
    }
};