#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

vector<vector<int>> add(vector<vector<int>> a, vector<vector<int>> b, int n)
{
    vector<int> g(n, 0);
    vector<vector<int>> c(n, g);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

vector<vector<int>> sub(vector<vector<int>> a, vector<vector<int>> b, int n)
{
    vector<int> g(n, 0);
    vector<vector<int>> c(n, g);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}

vector<vector<int>> strassens_multiply(vector<vector<int>> a, vector<vector<int>> b, int n)
{
    vector<int> g(n, 0);
    vector<vector<int>> c(n, g);
    if (n == 1)
    {
        c[0][0] = a[0][0] * b[0][0];
        return c;
    }
    int si = n / 2;
    vector<int> f(si, 0);
    vector<vector<int>> c11(si, f), c12(si, f), c21(si, f), c22(si, f), a11(si, f), a12(si, f), a21(si, f), a22(si, f), b11(si, f), b12(si, f), b21(si, f), b22(si, f), p1(si, f), p2(si, f), p3(si, f), p4(si, f), p5(si, f), p6(si, f), p7(si, f);
    for (int i = 0; i < si; i++)
    {
        for (int j = 0; j < si; j++)
        {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + si];
            a21[i][j] = a[i + si][j];
            a22[i][j] = a[i + si][j + si];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + si];
            b21[i][j] = b[i + si][j];
            b22[i][j] = b[i + si][j + si];
        }
    }
    p1 = strassens_multiply(a11, sub(b12, b22, si), si);
    p2 = strassens_multiply(add(a11, a12, si), b22, si);
    p3 = strassens_multiply(add(a21, a22, si), b11, si);
    p4 = strassens_multiply(a22, sub(b21, b11, si), si);
    p5 = strassens_multiply(add(a11, a22, si), add(b11, b22, si), si);
    p6 = strassens_multiply(sub(a12, a22, si), add(b21, b22, si), si);
    p7 = strassens_multiply(sub(a11, a21, si), add(b11, b12, si), si);

    c11 = sub(add(add(p5, p4, si), p6, si), p2, si);
    c12 = add(p1, p2, si);
    c21 = add(p3, p4, si);
    c22 = sub(add(p1, p5, si), add(p3, p7, si), si);

    for (int i = 0; i < si; i++)
    {
        for (int j = 0; j < si; j++)
        {
            c[i][j] = c11[i][j];
            c[i][j + si] = c12[i][j];
            c[i + si][j] = c21[i][j];
            c[i + si][j + si] = c22[i][j];
        }
    }
    return c;
}

int main()
{
    int r1, c1, r2, c2;
    cout << "enter the no of rows in matrix1 : ";
    cin >> r1;
    cout << "enter the no of columns in matrix1 : ";
    cin >> c1;
    cout << "enter the no of rows in matrix2 : ";
    cin >> r2;
    cout << "enter the no of columns in matrix2 : ";
    cin >> c2;
    int n = max(r1, max(r2, max(c1, c2)));
    if (n % 2 == 1)
    {
        n = n + 1;
    }
    vector<int> g(n, 0);
    vector<vector<int>> a(n, g), b(n, g);
    cout << "enter the elements in matrix1 : \n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "enter the elements in matrix2 : \n";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> b[i][j];
        }
    }
    auto start = high_resolution_clock::now();
    vector<vector<int>> c(n, g);
    c = strassens_multiply(a, b, n);
    cout << "the final multiplied matrix : \n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    auto end = high_resolution_clock::now();
    auto runtime = duration_cast<nanoseconds>(end - start).count();

    cout << "machine constant : " << runtime << " nanoseconds";
    return 0;
}
