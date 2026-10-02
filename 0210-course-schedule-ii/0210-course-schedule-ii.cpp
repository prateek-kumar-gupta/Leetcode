class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses , 0);
        vector<vector<int>> adj(numCourses);
        for(auto &v : prerequisites){
            int a = v[0];
            int b = v[1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        vector<int>ans ;
        queue<int>q;
        int count = 0 ;
        for(int i = 0 ; i < numCourses ; i++){
              if(indegree[i] == 0){
                ans.push_back(i);
                q.push(i);
                count++;
              }
        }
        while(!q.empty()){
           int a = q.front();
           q.pop();
           for(int &b : adj[a]){
            indegree[b]--;
            if(indegree[b]==0){
                ans.push_back(b);
                q.push(b);
                count++;
            }
           }
        }
        if(count==numCourses) return ans ;
        else return {};
    }
};