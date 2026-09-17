class Solution {
public:

   bool topological(unordered_map<int , vector<int>>& adj , int n , vector<int>&indegree){
    queue<int> q ;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(indegree[i] == 0 ) {q.push(i); count++;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int &v : adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                count++;
                q.push(v);
            }
        }
    }
    if(count == n ) return true ;
    else return false ;
   }
    bool canFinish(int num, vector<vector<int>>& pr) {
        vector<int> indegree(num , 0);
        
        unordered_map<int , vector<int>> adj ;
        for(auto &vec : pr){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topological(adj , num , indegree);
    }
};