#include <iostream>
#include <vector>
#include <queue>
#define n 9

using namespace std;
void initAdjMat(int adjMatrix[][n]);
void addEdgeM(int adjMatrix[][n], int x, int y);
void BFS_Matrix(int A[][n], int start);
void addEdgeL(vector<vector<int>> &A, int x, int y);
void BFS_List(vector<vector<int>> &A, int start);

int main()
{
    int adjMatrix[n][n];

    initAdjMat(adjMatrix);

    addEdgeM(adjMatrix, 0, 1);
    addEdgeM(adjMatrix, 0, 2);
    addEdgeM(adjMatrix, 1, 3);
    addEdgeM(adjMatrix, 1, 4);
    addEdgeM(adjMatrix, 2, 5);
    addEdgeM(adjMatrix, 2, 6);
    addEdgeM(adjMatrix, 6, 7);
    addEdgeM(adjMatrix, 6, 8);

    BFS_Matrix(adjMatrix, 3);

    vector<vector<int>> adjList(n);

    addEdgeL(adjList, 0, 1);
    addEdgeL(adjList, 0, 2);
    addEdgeL(adjList, 1, 3);
    addEdgeL(adjList, 1, 4);
    addEdgeL(adjList, 2, 5);
    addEdgeL(adjList, 2, 6);
    addEdgeL(adjList, 6, 7);
    addEdgeL(adjList, 6, 8);
    
    BFS_List(adjList, 3);
}

void initAdjMat(int adjMatrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}
void addEdgeM(int adjMatrix[][n], int x, int y)
{
    adjMatrix[x][y] = 1;
    adjMatrix[y][x] = 1;
}
void BFS_Matrix(int A[][n], int start)
{
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "Visiting seq: ";
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int neighbor = 0; neighbor < n; neighbor++)
        {
            if (A[curr][neighbor] && !visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
void addEdgeL(vector<vector<int>> &A, int x, int y)
{
    A[x].push_back(y);
    A[y].push_back(x);
}
void BFS_List(vector<vector<int>> &A, int start)
{
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "Visiting seq: ";
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int neighbor : A[curr])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
