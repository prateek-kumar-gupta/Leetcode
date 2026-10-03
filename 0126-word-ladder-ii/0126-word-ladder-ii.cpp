class Solution {
    unordered_map<string, vector<string>> adj;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string& beginWord) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for (auto& parent : adj[word]) {
            path.push_back(parent);
            dfs(parent, beginWord);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // If endWord is not in dictionary, no path exists
        if (st.find(endWord) == st.end()) return {};

        unordered_map<string, int> steps;
        queue<string> q;
        
        q.push(beginWord);
        steps[beginWord] = 0;
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            int step = steps[word];
            q.pop();

            // Stop processing further levels if we've reached the endWord
            if (word == endWord) break;

            string original = word;
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if (st.count(word)) {
                        // If visited for the first time
                        if (steps.find(word) == steps.end()) {
                            steps[word] = step + 1;
                            q.push(word);
                            adj[word].push_back(original);
                        } 
                        // If visited before, but forms another shortest path on the SAME level
                        else if (steps[word] == step + 1) {
                            adj[word].push_back(original);
                        }
                    }
                }
                word[i] = c; // Restore the character
            }
        }

        // If the endWord is reachable, backtrack to find all paths
        if (steps.find(endWord) != steps.end()) {
            path.push_back(endWord);
            dfs(endWord, beginWord);
        }
        
        return ans;
    }
};