#include <iostream>
#include <chrono>
#include "./mergesort.cpp"
using namespace std;
using namespace chrono;

template <class T1, class T2>
class Pair
{
public:
    T1 first;
    T2 second;
    Pair()
    {
        first = 0;
        second = 0;
    }
    Pair(T1 a, T2 b)
    {
        first = a;
        second = b;
    }
};

bool cmp(Pair<float, int> &a, Pair<float, int> &b)
{
    return a.first > b.first;
}

int main()
{
    int n, limit;
    cin >> n >> limit;
    int weight[n], profits[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
    }
    auto start = high_resolution_clock::now();
    Pair<float, int> profits_per_weight[n];
    for (int i = 0; i < n; i++)
    {
        float p = (float)profits[i] / (float)weight[i];
        profits_per_weight[i] = Pair(p, i);
    }

    mergesort(profits_per_weight, 0, n - 1, &cmp);
    int ans_profit = 0, ans_w[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (limit)
        {
            if (limit >= weight[profits_per_weight[i].second])
            {
                limit -= weight[profits_per_weight[i].second];
                ans_profit += profits[profits_per_weight[i].second];
                ans_w[profits_per_weight[i].second] = weight[profits_per_weight[i].second];
            }
            else
            {
                ans_profit += profits_per_weight[i].first * limit;
                ans_w[i] = limit;
                limit = 0;
            }
        }
        else
        {
            break;
        }
    }
    auto finish = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(finish - start);
    cout << "Profit : " << ans_profit << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "idx = " << i << ", weight =  " << ans_w[i] << "\n";
    }
    cout << "Time Taken is : " << duration.count() << " microseconds\n";
    return 0;
}