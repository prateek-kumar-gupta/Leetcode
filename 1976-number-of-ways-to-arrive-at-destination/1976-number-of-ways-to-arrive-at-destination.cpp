class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);

        distance[0] = 0;
        ways[0] = 1;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, 0});

        while(!pq.empty()) {

            auto a = pq.top();
            pq.pop();

            long long d = a.first;
            int node = a.second;

            if(d > distance[node])
                continue;

            for(auto &s : adj[node]) {

                int nextNode = s.first;
                long long newDist = d + s.second;

                if(newDist < distance[nextNode]) {

                    distance[nextNode] = newDist;
                    ways[nextNode] = ways[node];

                    pq.push({newDist, nextNode});
                }
                else if(newDist == distance[nextNode]) {

                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};