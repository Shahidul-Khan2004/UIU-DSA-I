#include <iostream>
#include <vector>
#include <queue>
#define n 9

using namespace std;
void addEdge(vector<vector<int>> &A, int x, int y);
bool isConnected(vector<vector<int>> &adj);

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

    isConnected(adjList) ? cout << "Connected" : cout << "Not Connected";
}

void addEdge(vector<vector<int>> &A, int x, int y)
{
    A[x].push_back(y);
    A[y].push_back(x);
}
bool isConnected(vector<vector<int>> &adj)
{
    if (adj.empty()) return true;
    vector<int> visited(adj.size(), 0);
    queue<int> q;
    visited[0] = 1;
    q.push(0);
    int seen = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                ++seen;
                q.push(v);
            }
        }
    }
    return seen == adj.size();
}
