class Solution {
public:
     vector<pair<int,int>> direction = {  {1 ,0} , {-1 , 0} , {0 , 1 } , {0 , -1 } , {-1 , -1 } , {1 , 1} , { -1 , 1} , {1 , -1} };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0 || grid[0][0] != 0 )
          return - 1;

        queue<pair<int,int>> q ;
         
        int level = 0 ;
        grid[0][0] = 1;
        q.push({0,0});
        while(!q.empty()){
            level++;
            int a = q.size();
        for(int i = 0 ; i < a ; i++ ){
            auto s = q.front();
            q.pop();
            int x = s.first;
            int y = s.second;
            if(x==n-1 && y==n-1) return level ;
           for(auto &z : direction){
            int j = z.first;
            int k = z.second;
            if(x+j<n && x+j>=0 && y+k<n && y+k>=0) {
                if(grid[x+j][y+k] == 0){
                    grid[x+j][y+k] = 1;
                    q.push({ x+j ,  y + k});
                }
            }
           }

        }
        }
        return -1 ;

    }
};