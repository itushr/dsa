#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(
            n,
            vector<pair<double, int>>()
        );
        priority_queue<pair<double, int>> pq;
        vector<double> probs(n, 0);

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        pq.push({ 1, start_node });
        probs[start_node] = 1;

        while(!pq.empty()){
            auto [prob, node] = pq.top();
            pq.pop();

            if(prob < probs[node]) continue;

            for(auto [w, neighbour]: adj[node]){
                if(prob*w > probs[neighbour]){
                    pq.push({ prob*w, neighbour });
                    probs[neighbour] = prob*w;
                }
            }
        }

        return probs[end_node];
    }
};