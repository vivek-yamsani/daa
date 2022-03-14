#include <iostream>
#include <climits>
#include <chrono>
using namespace std;

template <class T>
struct node
{
    T data;
    int priority;
};

template <class T>
class Priority_queue
{
public:
    struct node<T> *arr;
    int size;
    Priority_queue()
    {
        arr = new node<T>[100];
        size = 0;
    }
    void enqueue(T d, int priority)
    {
        // O(1)
        arr[size].data = d;
        arr[size].priority = priority;
        size++;
    }
    T dequeue()
    {
        // O(n) to find peek
        int maxp = INT_MIN, maxp_idx;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].priority > maxp)
            {
                maxp = arr[i].priority;
                maxp_idx = i;
            }
        }
        auto tmp = arr[size - 1];
        arr[size - 1] = arr[maxp_idx];
        arr[maxp_idx] = tmp;
        size--;
        return arr[size].data;
    }
    T peek()
    {
        // O(n)
        int maxp = INT_MIN, maxp_idx;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].priority > maxp)
            {
                maxp = arr[i].priority;
                maxp_idx = i;
            }
        }
        return arr[maxp_idx].data;
    }
};

int main()
{
    Priority_queue<int> p;
    int n;
    cin >> n;

    // enqueue,every case takes O(1) time
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++)
    {
        p.enqueue(i, n - i + 1);
    }
    auto finish1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(finish1 - start1);

    // next peek and dequeue are O(n)
    // so,all the best worst and average are => O(n)
    int arr[n];
    int i = 0;
    auto start2 = chrono::high_resolution_clock::now();
    while (p.size != 0)
    {
        arr[i++] = p.dequeue();
    }
    auto finish2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(finish2 - start2);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Time taken for Enqueue ops : " << duration1.count() << " nanoseconds \n";
    cout << "Time taken for dequeue & peak ops : " << duration2.count() << " nanoseconds \n";

    return 0;
}