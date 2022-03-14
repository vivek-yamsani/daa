#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

int linear_search(int a[], int target, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "Size of array : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        // cin >> a[i];
        a[i] = i;

    int key;
    cout << "Key to find : ";
    cin >> key;

    auto start = chrono::high_resolution_clock::now();

    int index = linear_search(a, key, n);

    auto finish = chrono::high_resolution_clock::now();

    auto run_time = chrono::duration_cast<chrono::microseconds>(finish - start);
    cout << "key index " << index << endl;
    cout << "\nTime for linear search : " << run_time.count() << "  microseconds \n";

    return 0;
}

// best case  key is present at 0 index
// worst case key is not present
// average case all possible case times/no of cases
// 10
// 8 6 12 5 9 7 4 3 16 18