#include <iostream>
#include <chrono>
using namespace std;

int partition(int arr[], int low, int high, int n)
{
    int pivot = low, i = low, j = high;
    while (i <= j)
    {
        while (i <= high && arr[i] <= arr[pivot])
            i++;
        while (j >= low && arr[j] > arr[pivot])
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int arr[], int low, int high, int n)
{
    if (low >= high)
        return;
    int pivot = partition(arr, low, high, n);
    quick_sort(arr, low, pivot - 1, n);
    quick_sort(arr, pivot + 1, high, n);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        // cin >> a[i];
        a[i] = n - i;
    }

    auto start = chrono::high_resolution_clock::now();
    quick_sort(a, 0, n - 1, n);
    auto finish = chrono::high_resolution_clock::now();
    auto run_time = chrono::duration_cast<chrono::microseconds>(finish - start);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
    cout << "\nTime : " << run_time.count() << "  microseconds \n";

    return 0;
}