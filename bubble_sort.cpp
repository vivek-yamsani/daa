#include <iostream>
#include <chrono>
// #include <algorithm>
using namespace std;

void bubble_sort(int *arr, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Size of array : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = n - i;

    auto start = chrono::high_resolution_clock::now();
    bubble_sort(a, n);
    auto finish = chrono::high_resolution_clock::now();

    auto run_time = chrono::duration_cast<chrono::microseconds>(finish - start);

    cout << "\nTime  : " << run_time.count() << "  microseconds \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
