#include <iostream>
#include <vector>
// number of nodes
#define n 4

using namespace std;

void addEdge(vector<vector<int>> &list, int a, int b);
void printList(vector<vector<int>> &list);

int main()
{
    vector<vector<int>> list(n);

    addEdge(list, 1, 2);
    addEdge(list, 1, 3);
    addEdge(list, 2, 4);
    addEdge(list, 3, 2);

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