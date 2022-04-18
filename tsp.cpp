#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, path_length = 0, count = 0, j = 0, start;
    cout << "enetr no of vertices : ";
    cin >> n;
    cout << "enetr no of edges : ";
    cin >> e;
    cout << "enter the vertex as starting point: ";
    cin >> start;
    int i = start - 1;
    int min_len = INT_MAX;
    vector<vector<int>> sales_man(n, vector<int>(n, -1));
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        sales_man[a][b] = c;
        sales_man[b][a] = c;
    }
    vector<bool> visited_vertex(n, false);
    visited_vertex[i] = true;
    int *route = (int *)malloc(sales_man.size() * sizeof(int));
    while (i < sales_man[i].size() && j < sales_man[i].size())
    {
        if (count >= sales_man[i].size() - 1)
        {
            break;
        }
        if (j != i && (visited_vertex[j] == 0))
        {
            if (sales_man[i][j] < min_len)
            {
                min_len = sales_man[i][j];
                route[count] = j + 1;
            }
        }
        j++;
        if (j == sales_man[i].size())
        {
            cout << "minimum lenght from the vertex " << i + 1 << " to " << route[count] << " = " << min_len << endl;
            path_length += min_len;
            min_len = INT_MAX;
            visited_vertex[route[count] - 1] = 1;
            j = 0;
            i = route[count] - 1;
            count++;
        }
    }
    i = route[count - 1] - 1;
    min_len = sales_man[i][start - 1];
    cout << "minimum lenght from the vertex " << i + 1 << " to " << start << " = " << min_len << endl;
    path_length += min_len;
    cout << "minimum length to be travelled by the sales person is = ";
    cout << path_length;
}
