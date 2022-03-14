#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

int binary_search(int a[], int target, int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] > target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Size of array : ";
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        // cin >> a[i];
        a[i] = i;
    sort(a, a + n);
    int key;
    cout << "Key to find : ";
    cin >> key;

    auto start = chrono::high_resolution_clock::now();

    int index = binary_search(a, key, n);

    auto finish = chrono::high_resolution_clock::now();

    auto run_time = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "key index " << index << endl;
    cout << "\nTime : " << run_time.count() << "  nanoseconds \n";
    return 0;
}
// 10
// 3 4 5 6 7 8 9 12 16 18