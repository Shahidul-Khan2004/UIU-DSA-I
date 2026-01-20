#include <iostream>
#include <vector>
#include <queue>
#define n 9

using namespace std;
void addEdge(vector<vector<int>> &A, int x, int y);
bool isBipartite(vector<vector<int>> &A);

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

    isBipartite(adjList) ? cout << "Bipartite" : cout << "Not Bipartite";
}

void addEdge(vector<vector<int>> &A, int x, int y)
{
    A[x].push_back(y);
    A[y].push_back(x);
}
bool isBipartite(vector<vector<int>> &A)
{
    vector<int> color(n, -1);
    queue<int> q;
    color[0] = 0;
    q.push(0);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : A[curr])
        {
            if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[curr];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[curr])
            {
                return false;
            }
        }
    }
    return true;
}
