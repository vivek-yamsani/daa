#include <iostream>
#include <vector>
using namespace std;

class Disjoint_Set
{
    int *parent, *rank;
    int v;

public:
    Disjoint_Set(int _v)
    {
        parent = new int[_v];
        rank = new int[_v];
        v = _v;
        for (int i = 0; i < v; i++)
            parent[i] = i, rank[i] = 0;
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

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, pair<int, int>>> edges(e);
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = make_pair(wt, make_pair(u, v));
    }
    sort(edges.begin(), edges.end());
    int count = n - 1,it = 0;
    
    return 0;
}