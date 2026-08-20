#include <vector>
#include <climits>
#include <queue>
#include <functional>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(
            n + 1,
            vector<pair<int, int>>());
        vector<int> time(n + 1, INT_MAX);

        for (vector<int> i : times)
        {
            adj[i[0]].push_back({i[2], i[1]});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        pq.push({0, k});
        time[k] = 0;

        while (!pq.empty())
        {
            auto [t, node] = pq.top();
            pq.pop();

            if (t > time[node])
                continue;

            for (auto [w, neighbour] : adj[node])
            {
                if (t + w < time[neighbour])
                {
                    pq.push({t + w, neighbour});
                    time[neighbour] = t + w;
                }
            }
        }

        int maxi = INT_MIN;

        for (int i = 1; i < n + 1; i++)
        {
            if (time[i] > maxi)
            {
                maxi = time[i];
            }
        }

        if (maxi == INT_MAX)
            return -1;
        else
            return maxi;
    }
};