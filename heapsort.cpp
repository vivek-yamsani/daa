#include <iostream>
#include <chrono>
using namespace std;

void max_it(int arr[], int index, int n)
{

    while (index <= n)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != index)
        {
            int temp = arr[largest];
            arr[largest] = arr[index];
            arr[index] = temp;

            index = largest;
        }
        else
            break;
    }
}

void max_heapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != index)
    {
        int temp = arr[largest];
        arr[largest] = arr[index];
        arr[index] = temp;

        max_heapify(arr, largest, n);
    }
}

void build_heap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        // max_heapify(arr, i, n);
        max_it(arr, i, n);
    }
}

void heap_sort(int arr[], int n)
{
    build_heap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // max_heapify(arr, 0, i);
        max_it(arr, 0, i);
    }
}

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        // cin >> v[i];
        v[i] = n - i;
    }
    auto start = chrono::high_resolution_clock::now();
    heap_sort(v, n);
    auto finish = chrono::high_resolution_clock::now();
    auto run_time = chrono::duration_cast<chrono::microseconds>(finish - start);
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "\nTime : " << run_time.count() << "  microseconds \n";
}