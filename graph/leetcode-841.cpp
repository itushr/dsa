#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<bool> &visited, vector<vector<int>> &rooms, int source, int &nvisited)
    {
        visited[source] = true;

        for (int neighbour : rooms[source])
        {
            if (!visited[neighbour])
            {
                nvisited++;
                dfs(visited, rooms, neighbour, nvisited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> visited(rooms.size(), false);

        int nvisited = 1;

        dfs(visited, rooms, 0, nvisited);

        return nvisited == rooms.size();
    }
};