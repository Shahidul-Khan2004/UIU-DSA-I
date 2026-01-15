#include <iostream>
#include <vector>
#include <stack>
// number of nodes
#define n 6

using namespace std;

void addEdge(vector<vector<int>> &list, int a, int b);
void printList(vector<vector<int>> &list);
void DFS(vector<vector<int>> &list, int startNode);

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

    DFS(list, 1);

    printList(list);
}

void addEdge(vector<vector<int>> &list, int a, int b)
{
    // list is zero indexed
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

void DFS(vector<vector<int>> &list, int startNode)
{
    vector<int> visited(n, false);
    stack<int> s;
    s.push(startNode);

    cout << "Visited Sequence: ";
    while (!s.empty())
    {
        int currentNode = s.top();
        s.pop();
        if (!visited[currentNode - 1])
        {
            visited[currentNode - 1] = true;
            cout << currentNode << " ";
            for (int node : list[currentNode - 1])
            {
                if (!visited[node - 1])
                {
                    s.push(node);
                }
            }
        }
    }
    cout << endl;
}