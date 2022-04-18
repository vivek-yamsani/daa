#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, e;
    cout << "enter no of vertices : ";
    cin >> n;
    cout << "enter no of edges : ";
    cin >> e;
    vector<vector<int>> adj_list(n);
    cout << "enter the starting and ending vertices of each edge : \n";
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            for (auto itr : adj_list[i])
            {
                if (!visited[itr])
                {
                    visited[itr] = true;
                    visited[i] = true;
                    break;
                }
            }
        }
    }
    cout << "the vertex cover will be : ";
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}
