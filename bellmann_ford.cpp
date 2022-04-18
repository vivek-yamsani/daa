#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

void bellman_ford(vector<pair<int, pair<int, int>>> v, int src, int n)
{
    int e = v.size();
    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int wt = v[j].first;
            int st = v[j].second.first;
            int end = v[j].second.second;
            dis[end] = min(dis[end], dis[st] + wt);
        }
    }
    for (int j = 0; j < e; j++)
    {
        int wt = v[j].first;
        int st = v[j].second.first;
        int end = v[j].second.second;
        if (dis[st] + wt < dis[end])
        {
            cout << "negative weighted cycle found";
            return;
        }
    }
    cout << "the distance from " << src << " vertex to all other vertices are : \n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "-->" << dis[i] << endl;
    }
}
int main()
{
    int n, e;
    cout << "enter no of vertices : ";
    cin >> n;
    cout << "enter no of edges : ";
    cin >> e;
    vector<pair<int, pair<int, int>>> v;
    cout << "enter the weight,start and end vertices of each edge : \n";
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(a, make_pair(b, c)));
    }
    int src;
    cout << "enter the starting vertex : ";
    cin >> src;
    bellman_ford(v, src, n);
    return 0;
}
