#include <iostream>
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
    node<T> *arr;

public:
    int size;
    Priority_queue()
    {
        arr = new node<T>[100];
        size = 0;
    }
    void heapify(int idx)
    {
        int largest = idx;
        int left = 2 * idx + 1, right = 2 * idx + 2;

        if (left < size && arr[left].priority > arr[largest].priority)
            largest = left;
        if (right < size && arr[right].priority > arr[largest].priority)
            largest = right;

        if (largest != idx)
        {
            auto tmp = arr[idx];
            arr[idx] = arr[largest];
            arr[largest] = tmp;

            heapify(largest);
        }
    }
    void enqueue(int d, int priority)
    {
        arr[size].data = d;
        arr[size].priority = priority;
        int idx = size++, parent = (idx - 1) / 2;
        while (idx > 0 && arr[idx].priority > arr[parent].priority)
        {
            auto tmp = arr[idx];
            arr[idx] = arr[parent];
            arr[parent] = tmp;

            idx = parent;
            parent = (idx - 1) / 2;
        }
    }
    void dequeue()
    {
        // O(log n)
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    T peek()
    {
        // O(1)
        return arr[0].data;
    }
};

int main()
{
    Priority_queue<int> p;
    int n;
    cin >> n;
    // enqueue worst case
    // every time it should go to end level of heap => O(log n)

    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++)
    {
        p.enqueue(n - i + 1, i);
    }
    auto finish1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(finish1 - start1);

    // next peek and dequeue are O(log n)
    // so,all the best worst and average are => O(log n)
    int arr[n];
    int i = 0;
    auto start2 = chrono::high_resolution_clock::now();
    while (p.size != 0)
    {
        arr[i++] = p.peek();
        p.dequeue();
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