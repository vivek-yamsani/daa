#include <iostream>
#include <chrono>
using namespace std;

template <class T>
void merge(T a[], int s, int e, int mid, bool (*cmp)(T &a, T &b))
{
    int n = mid - s + 1, m = e - mid;
    T p[n], q[m];
    for (int i = 0; i < n; i++)
    {
        p[i] = a[i + s];
    }
    for (int i = 0; i < m; i++)
    {
        q[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = s;
    while (i < n && j < m)
    {
        if (!cmp(p[i], q[j]))
        {
            a[k++] = q[j++];
        }
        else
        {
            a[k++] = p[i++];
        }
    }
    while (i < n)
        a[k++] = p[i++];
    while (j < m)
        a[k++] = q[j++];

    return;
}

template <class T>
void mergesort(T a[], int s, int e, bool (*cmp)(T &a, T &b))
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergesort(a, s, mid, cmp);
    mergesort(a, mid + 1, e, cmp);
    merge(a, s, e, mid, cmp);
}

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         // cin >> a[i];
//         a[i] = n - i;
//     }

//     auto start = chrono::high_resolution_clock::now();
//     mergesort(a, 0, n - 1);
//     auto finish = chrono::high_resolution_clock::now();
//     auto run_time = chrono::duration_cast<chrono::microseconds>(finish - start);

//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";

//     cout << endl;
//     cout << "\nTime : " << run_time.count() << "  microseconds \n";
//     return 0;
// }