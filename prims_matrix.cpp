#include <iostream>
#include <chrono>
using namespace std;

int minKey(int key[], bool mst[], int n)
{
    int mn = 1e9, idx;

    for (int i = 0; i < n; i++)
    {
        if ((mst[i] == false) && (key[i] < mn))
            mn = key[i], idx = i;
    }

    return idx;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **adj = new int *[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = new int[n];
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }
    auto start = chrono::high_resolution_clock::now();
    int parent[n];
    int key[n];
    bool mstSet[n];

    for (int i = 0; i < n; i++)
        key[i] = 1e9, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {

        int u = minKey(key, mstSet, n);

        mstSet[u] = true;

        for (int v = 0; v < n; v++)

            if ((adj[u][v] != 0) && (mstSet[v] == false) && (adj[u][v] < key[v]))
                parent[v] = u, key[v] = adj[u][v];
    }

    auto finish = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(finish - start).count();

    cout << "MST contains : \n";
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "-" << i << "\t" << adj[parent[i]][i] << "\n";
    }
    cout << "Time taken : " << duration << " microseconds\n";

    return 0;
}