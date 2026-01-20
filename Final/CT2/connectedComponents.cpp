#include <iostream>
#include <vector>
#include <queue>
#define n 9

using namespace std;
void addEdge(vector<vector<int>> &A, int x, int y);
vector<vector<int>> findConnectedComponents(vector<vector<int>> &adj);

int main()
{
    vector<vector<int>> adjList(n);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 5);
    //addEdge(adjList, 2, 6);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 6, 8);

    vector<vector<int>> components = findConnectedComponents(adjList);
    
    cout << "Connected Components:" << endl;
    for (int i = 0; i < components.size(); i++)
    {
        cout << "Component " << i + 1 << ": ";
        for (int node : components[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

void addEdge(vector<vector<int>> &A, int x, int y)
{
    A[x].push_back(y);
    A[y].push_back(x);
}

vector<vector<int>> findConnectedComponents(vector<vector<int>> &adj)
{
    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            queue<int> q;
            visited[i] = true;
            q.push(i);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                component.push_back(curr);

                for (int neighbor : adj[curr])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            components.push_back(component);
        }
    }

    return components;
}
