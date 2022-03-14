#include <iostream>
#include <chrono>
#include "./mergesort.cpp"
using namespace std;
using namespace chrono;

template <class T1, class T2>
class Pair
{
public:
    T1 first;
    T2 second;
    Pair()
    {
        first = 0;
    }
    Pair(T1 a, T2 b)
    {
        first = a;
        second = b;
    }
};

class Disjoint_set
{
public:
    int n;
    int *parent, *rank;
    Disjoint_set(int n_val)
    {
        n = n_val;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int vertex)
    {
        if (parent[vertex] == vertex)
            return vertex;

        int root_parent = find(parent[vertex]);
        return parent[vertex] = root_parent;
    }
    void Union(int vertex1, int vertex2)
    {
        int find1 = find(vertex1), find2 = find(vertex2);
        if (find1 == find2)
            return;

        if (rank[find1] > rank[find2])
        {
            parent[find2] = find1;
        }
        else if (rank[find2] > rank[find1])
        {
            parent[find1] = find2;
        }
        else
        {
            parent[find1] = find2;
            rank[find2]++;
        }
    }
};

bool cmp(Pair<int, Pair<int, int>> &a, Pair<int, Pair<int, int>> &b)
{
    return a.first < b.first;
}

int main()
{
    int n, e;
    cin >> n >> e;
    Pair<int, Pair<int, int>> edges[e];
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = Pair(wt, Pair(u, v));
    }
    auto start = high_resolution_clock::now();
    mergesort(edges, 0, e - 1, &cmp);
    Disjoint_set set(n);
    Pair<int, int> mst_edges[n];
    int iterator = 0, cost_of_mst;
    for (auto i : edges)
    {
        if (iterator == n - 1)
            break;
        int u = i.second.first, v = i.second.second;
        if (set.find(u) != set.find(v))
        {
            mst_edges[iterator++] = Pair(u, v);
            set.Union(u, v);
            cost_of_mst += i.first;
        }
    }
    auto finish = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(finish - start).count();
    cout << "\nEdges in MST :\n";
    for (int i = 0; i < iterator; i++)
    {
        cout << mst_edges[i].first << " " << mst_edges[i].second << "\n";
    }
    cout << "\nCost of MST : " << cost_of_mst << "\n";
    cout << "Time taken is : " << duration << " microseconds \n";
    return 0;
}