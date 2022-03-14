#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int min_index(int *arr, int s, int e)
{
    int ans = s, mn = arr[s];
    for (int i = s; i <= e; i++)
    {
        if (mn > arr[i])
        {
            ans = i;
            mn = arr[i];
        }
    }

    return ans;
}

void selection_sort(int *arr, int n)
{
    int s = 0, e = n - 1;
    while (s < e)
    {
        // worst O(n2)
        int mn_index = min_index(arr, s, e);
        if (arr[mn_index] != arr[s])
            swap(arr, s, mn_index);
        s++;
    }
}

int main()
{
    int n;
    cout << "Size of array : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
        // a[i] = n - i;

    auto start = chrono::high_resolution_clock::now();
    selection_sort(a, n);
    auto finish = chrono::high_resolution_clock::now();

    auto run_time = chrono::duration_cast<chrono::microseconds>(finish - start);

    cout << "\nTime  : " << run_time.count() << "  microseconds \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
