#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

int binary_search(int a[], int target, int l, int r)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2;
    if (a[mid] == target)
        return mid;
    if (a[mid] > target)
        return binary_search(a, target, l, mid - 1);

    return binary_search(a, target, mid + 1, r);
}

int main()
{
    int n;
    cout << "Size of array with random elements : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        // cin >> a[i];
        a[i] = i;
    // sort(a, a + n);
    int key;
    cout << "Key to find : ";
    cin >> key;

    auto start = chrono::high_resolution_clock::now();

    int index = binary_search(a, key, 0, n - 1);

    auto finish = chrono::high_resolution_clock::now();

    auto run_time = chrono::duration_cast<chrono::nanoseconds>(finish - start);

    cout << "key index " << index << endl;

    cout << "\nTime : " << run_time.count() << "  nanoseconds \n";
    return 0;
}