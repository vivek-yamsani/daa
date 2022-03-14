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

void insertion_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i, key = arr[j];
        // 1 2 3 4 12 9 828 3494 
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

int main()
{
    int n;
    cout << "Size of array : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        // cin>>a[i];
        a[i] = n - i;

    auto start = chrono::high_resolution_clock::now();
    insertion_sort(a, n);
    auto finish = chrono::high_resolution_clock::now();

    auto run_time = chrono::duration_cast<chrono::microseconds>(finish - start);

    cout << "\nTime  : " << run_time.count() << "  microseconds \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
