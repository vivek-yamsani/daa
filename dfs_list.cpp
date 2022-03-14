#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int st, vector<int> &ans)
{
    visited[st] = 1;
    ans.push_back(st);
    for (int i : adj[st])
    {
        if (!visited[i])
        {
            dfs(adj, visited, i, ans);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto start = chrono::high_resolution_clock::now();
    vector<bool> visited(n, 0);
    vector<int> traversal;
    dfs(adj, visited, 0, traversal);
    auto finish = chrono::high_resolution_clock::now();
    for (auto i : traversal)
        cout << i << " ";
    cout << endl;
    auto duration = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
    cout << "Time for traversal : " << duration << " nanoseconds";
}