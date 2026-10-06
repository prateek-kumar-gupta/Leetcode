class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights) {
            int u = f[0];
            int v = f[1];
            int price = f[2];

            adj[u].push_back({v, price});
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;

        pq.push({0, src, 0});

        while(!pq.empty()) {

            auto [cost, city, flights_used] = pq.top();
            pq.pop();

            if(city == dst)
                return cost;

            if(flights_used == k + 1)
                continue;

            for(auto &p : adj[city]) {

                int next = p.first;
                int price = p.second;

                int newCost = cost + price;
                int newFlights = flights_used + 1;

                if(newCost < dist[next][newFlights]) {

                    dist[next][newFlights] = newCost;

                    pq.push({newCost,
                          next,
                        newFlights });
                }
            }
        }

        return -1;
    }
};