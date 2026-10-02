class Solution {
public:

    bool safe(vector<vector<int>>& graph, int i, vector<int>& state) {

        // Currently in recursion path -> cycle
        if(state[i] == 1)
            return true;

        // Already processed and safe
        if(state[i] == 2)
            return false;

        // Mark as currently visiting
        state[i] = 1;

        for(int &v : graph[i]) {

            if(safe(graph, v, state))
                return true;
        }

        // No cycle found -> safe
        state[i] = 2;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int v = graph.size();
        vector<int> state(v, 0);

        vector<int> ans;

        for(int i = 0; i < v; i++) {

            if(!safe(graph, i, state))
                ans.push_back(i);
        }

        return ans;
    }
};