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
public:
    struct node<T> *arr;
    int size;
    Priority_queue()
    {
        arr = new node<T>[1000];
        size = 0;
    }
    // these are stored in ascending order of priority
    // ascending 
    void enqueue(T data, int priority)
    {
        // O(n)
        int j = size - 1;
        for (; j >= 0; j--)
        {
            if (priority < arr[j].priority)
            {
                arr[j + 1] = arr[j];
            }
            else if (priority == arr[j].priority)
            {
                // first pushed element will be first in the queue
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1].data = data;
        arr[j + 1].priority = priority;
        size++;
    }
    void dequeue()
    {
        // O(1)
        size--;
    }
    T peek()
    {
        // O(1)
        return arr[size - 1].data;
    }
};

int main()
{
    Priority_queue<int> p;
    int n;
    cin >> n;
    // enqueue worst case
    // every time it should go to start of array

    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++)
    {
        p.enqueue(i, n - i + 1);
    }
    auto finish1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(finish1 - start1);

    // next peek and dequeue are O(1)
    // so,all the best worst and average are => O(1)
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