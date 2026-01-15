#include <iostream>
// number of nodes in the graph
#define n 4

using namespace std;

void init(int arr[][n]);
void printAdjacencyMatrix(int arr[][n]);
void connectNodes(int arr[][n], int a, int b);

int main()
{
    int arr[n][n];
    // init the array with zeros
    init(arr);
    // connect the nodes
    connectNodes(arr, 1, 2);
    connectNodes(arr, 1, 3);
    connectNodes(arr, 3, 2);
    connectNodes(arr, 2, 4);
    // print the array in Adjacency matrix style
    printAdjacencyMatrix(arr);
}

void init(int arr[][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
}

void printAdjacencyMatrix(int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void connectNodes(int arr[][n], int a, int b)
{
    a = a - 1;
    b = b - 1;
    arr[a][b] = 1;
    arr[b][a] = 1;
}