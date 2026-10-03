class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_map<string, vector<string>> adj;

      vector<string> words = wordList;
      words.push_back(beginWord);

        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {

                int dif = 0;

                for(int k = 0; k < words[i].size(); k++) {
                    if(words[i][k] != words[j][k])
                        dif++;
                }

                if(dif == 1) {
                    adj[words[i]].push_back(words[j]);
                    adj[words[j]].push_back(words[i]);
                }
            }
        }
        // solving with shortest distance 
        unordered_map<string, int> dist;
        queue<string>q;
        q.push(beginWord);
        for(int i = 0 ; i < wordList.size() ; i++){
            dist[wordList[i]] = 0 ;
        }
         dist[beginWord] = 1;
         dist[endWord] = 0 ;
        while(!q.empty()){
           string   s = q.front();
           int d = dist[s];
           q.pop();
           for(string &a : adj[s]){
            if(dist[a]==0) {dist[a] = d + 1; q.push(a);}
            else dist[a] = min(d+1 , dist[a]);
           }
        }
        return dist[endWord];
    }
};