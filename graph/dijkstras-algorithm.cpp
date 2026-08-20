#include <vector>
#include <queue>
#include <climits>
#include <functional>
using namespace std;

vector<int> dijkstras(
    int n,
    vector<vector<pair<int, int>>> &adj,
    int source)
{
    vector<int> dist(n, INT_MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty())
    {
        auto [distance, node] = pq.top();
        pq.pop();

        if (distance > dist[node])
            continue;

        for (auto [neighbour, weight] : adj[node])
        {

            if (distance + weight < dist[neighbour])
            {
                dist[neighbour] = distance + weight;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}