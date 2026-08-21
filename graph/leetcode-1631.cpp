#include <vector>
#include <climits>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> efforts(
            m,
            vector<int>(n, INT_MAX)
        );
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});
        efforts[0][0] = 0;

        while(!pq.empty()){
            auto [effort, node] = pq.top();
            pq.pop();

            if(effort > efforts[node.first][node.second]) continue;

            //top
            if(node.first > 0 && max(abs(heights[node.first][node.second]-heights[node.first-1][node.second]), effort) < efforts[node.first-1][node.second]) {
                efforts[node.first-1][node.second] = max(abs(heights[node.first][node.second]-heights[node.first-1][node.second]), effort);
                pq.push({ efforts[node.first-1][node.second], {node.first-1, node.second} });
            }

            //bottom
            if(node.first < m-1 && max(abs(heights[node.first][node.second]-heights[node.first+1][node.second]), effort) < efforts[node.first+1][node.second]) {
                efforts[node.first+1][node.second] = max(abs(heights[node.first][node.second]-heights[node.first+1][node.second]), effort);
                pq.push({ efforts[node.first+1][node.second], {node.first+1, node.second} });
            }

            //left
            if(node.second > 0 && max(abs(heights[node.first][node.second]-heights[node.first][node.second-1]), effort) < efforts[node.first][node.second-1]) {
                efforts[node.first][node.second-1] = max(abs(heights[node.first][node.second]-heights[node.first][node.second-1]), effort);
                pq.push({ efforts[node.first][node.second-1], {node.first, node.second-1} });
            }

            //right
            if(node.second < n-1 && max(abs(heights[node.first][node.second]-heights[node.first][node.second+1]), effort) < efforts[node.first][node.second+1]) {
                efforts[node.first][node.second+1] = max(abs(heights[node.first][node.second]-heights[node.first][node.second+1]), effort);
                pq.push({ efforts[node.first][node.second+1], {node.first, node.second+1} });
            }
        }

        return efforts[m-1][n-1];
    }
};