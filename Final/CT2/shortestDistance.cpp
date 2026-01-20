#include <iostream>
#include <vector>
#include <queue>
#define n 9

using namespace std;
void addEdge(vector<vector<int>> &A, int x, int y);
int shortestDistance(vector<vector<int>> &adj, int startNode, int endNode);

int main()
{
    vector<vector<int>> adjList(n);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 2, 6);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 6, 8);

    int start = 0, end = 8;
    int dist = shortestDistance(adjList, start, end);
    cout << "Shortest distance from " << start << " to " << end << " is: " << dist << endl;
}

void addEdge(vector<vector<int>> &A, int x, int y)
{
    A[x].push_back(y);
    A[y].push_back(x);
}

int shortestDistance(vector<vector<int>> &adj, int startNode, int endNode)
{
    if (startNode == endNode)
        return 0;

    vector<int> distance(n, -1);
    queue<int> q;

    distance[startNode] = 0;
    q.push(startNode);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : adj[curr])
        {
            if (distance[neighbor] == -1)
            {
                distance[neighbor] = distance[curr] + 1;
                
                if (neighbor == endNode)
                    return distance[neighbor];
                
                q.push(neighbor);
            }
        }
    }

    return -1; // Should not reach here if graph is connected
}
