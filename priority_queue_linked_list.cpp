#include <iostream>
#include <chrono>
using namespace std;

template <class T>
struct node
{
    T data;
    int priority;
    node *next;
    node(T d, int p)
    {
        data = d;
        priority = p;
        next = NULL;
    }
};

template <class T>
class Priority_queue
{
public:
    node<T> *head;
    Priority_queue()
    {
        head = NULL;
    }
    void enqueue(T d, int priority)
    {
        // O(n)
        node<T> *temp = new node<T>(d, priority);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        node<T> *p = head, *prev;
        while (p != NULL)
        {
            if (p->priority >= priority)
            {
                prev = p;
                p = p->next;
            }
            else
                break;
        }
        if (p == head)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            temp->next = prev->next;
            prev->next = temp;
        }
    }
    void dequeue()
    {
        // O(1)
        if (head == NULL)
        {
            cout << "empty queue" << endl;
            return;
        }
        node<T> *p = head;
        head = head->next;
        delete (p);
    }
    T peek()
    {
        // O(1)
        if (head == NULL)
        {
            cout << "empty queue" << endl;
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Priority_queue<int> p;
    int n;
    cin >> n;
    // enqueue worst case
    // every time it should go to end of the list => O(n)

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
    while (p.head != NULL)
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