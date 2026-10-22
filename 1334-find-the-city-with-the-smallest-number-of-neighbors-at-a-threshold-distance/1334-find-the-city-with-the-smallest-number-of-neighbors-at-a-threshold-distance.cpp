class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n , vector<int>(n , 1e9)) ;
        for(int i = 0 ; i < edges.size() ; i++ ){
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                     if(i==j) matrix[i][j] = 0 ;
                     // via k ;
                     else 
                     matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
            }
        }
        }
        int ans = 0 ;
        int curr = n ;
        for(int i = 0 ; i < n ; i++){
            int cities = 0 ;
            for(int j = 0 ; j <n ; j++){
                 if(matrix[i][j] <= distanceThreshold) cities++;
                 if(cities > curr) break ;
            }
            if(cities <= curr){
                curr = cities ;
                ans = i ;
            }
        }
        return ans ;
    }
};