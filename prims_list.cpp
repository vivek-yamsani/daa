#include <iostream>
#include <vector>
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
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    auto start = chrono::high_resolution_clock::now();
    int parent[n];
    int key[n];
    bool mstSet[n];

    for (int i = 0; i < n; i++)
        key[i] = 1e9, mstSet[i] = false, parent[i] = -1;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {

        int u = minKey(key, mstSet, n);

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            if (mstSet[it.first] == false && it.second < key[it.first])
                parent[it.first] = u, key[it.first] = it.second;
        }
    }

    auto finish = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(finish - start).count();

    cout << "MST contains : \n";
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "-" << i << "\n";
    }
    cout << "Time taken : " << duration << " microseconds\n";

    return 0;
}