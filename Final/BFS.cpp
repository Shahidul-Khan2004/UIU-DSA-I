#include <iostream>
#include <vector>
#include <queue>
// number of nodes
#define n 6

using namespace std;

void addEdge(vector<vector<int>> &list, int a, int b);
void printList(vector<vector<int>> &list);
void BFS(vector<vector<int>> &list, int startNode);

int main()
{
    vector<vector<int>> list(n);

    addEdge(list, 1, 2);
    addEdge(list, 1, 4);
    addEdge(list, 2, 3);
    addEdge(list, 2, 5);
    addEdge(list, 3, 6);
    addEdge(list, 4, 5);
    addEdge(list, 5, 6);

    BFS(list, 1);

    printList(list);
}

void addEdge(vector<vector<int>> &list, int a, int b)
{
    //list is zero indexed
    list[a - 1].push_back(b);
    list[b - 1].push_back(a);
}

void printList(vector<vector<int>> &list)
{
    int size = list.size();
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1;
        for (int node : list[i])
            cout << " -> " << node;
        cout << " -> NULL " << endl;
    }
}

void BFS(vector<vector<int>> &list, int startNode) {
    vector<int> visited(n, false);
    queue<int> q;
    visited[startNode-1] = true;
    q.push(startNode);
    
    cout << "Visited Sequence: ";
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int node: list[currentNode - 1]) {
            if(!visited[node - 1]) {
                visited[node - 1] = true;
                q.push(node);
            }
        }
    }
    cout << endl;
}