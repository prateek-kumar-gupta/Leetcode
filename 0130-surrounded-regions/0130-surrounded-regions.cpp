class Solution {
public:
     void dfs(vector<vector<char>>&grid , int i , int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i <0 || i >= n || j < 0 || j >= m) return ;
        if(grid[i][j]=='X' || grid[i][j]=='1')return ;
          grid[i][j] = '1';
          dfs(grid , i + 1 , j);
          dfs(grid , i - 1 , j);
          dfs(grid , i , j + 1);
          dfs(grid , i , j -1 );
     }
    void solve(vector<vector<char>>& grid) {
        int  n = grid.size();
        int m = grid[0].size();
        int i = 0 ; int j = 0 ;
         int ans = 0 ;
         for(j = 0 ; j < m ; j++){
            if(grid[i][j]=='O'){
                dfs(grid , i , j);
            }
         }
         i = n - 1;
         for(j = 0 ; j < m ; j++){
            if(grid[i][j]=='O'){
                dfs(grid , i , j);
            }
         }
         j = 0 ;
         for(i = 0 ; i< n ; i++){
          if(grid[i][j]=='O'){
                dfs(grid , i , j);
            }
         }
         j = m - 1; 
         for(i = 0 ; i< n ; i++){
          if(grid[i][j]=='O'){
                dfs(grid , i , j);
            }
         }
         for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < m ; j++){
                if(grid[i][j] == '1') grid[i][j] = 'O';
                else grid[i][j] = 'X';
            }
         }
    }
};