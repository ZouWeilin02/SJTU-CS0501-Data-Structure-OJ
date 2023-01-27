#include<cstdio>

using namespace std;

int main()
{
    
}






/*
#include <cstdio>
#include <algorithm>

int a[15][15], p[15], n, answer;

int invertion(int v[], int k)
{
    int r = 0;
    for (int i = 1; i <= k; i++)
        for (int j = i + 1; j <= k; j++)
            if (v[i] > v[j])
                r++;
    return r;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    do
    {
        int term = 1;
        for (int i = 1; i <= n; i++)
            term *= a[i][p[i]];
        term *= (invertion(p, n) & 1) ? -1 : 1;
        answer += term;
    } while (std::next_permutation(p + 1, p + n + 1));
    printf("%d\n", answer);
    return 0;
}



#include <cstdio>

int a[105], n;

int det(int *v, int k)
{
    if (k == 1)
        return *v;
    int r = 0;
    for (int p = 0; p < k; p++)
    {
        int *s = new int[(k - 1) * (k - 1)];
        for (int i = 0; i < k - 1; i++)
            for (int j = 0; j < k - 1; j++)
                *(s + i * (k - 1) + j) = *(v + (i + 1) * k + (j < p ? j : (j + 1)));
        r += ((p & 1) ? -1 : 1) * *(v + p) * det(s, k - 1);
        delete[] s;
    }
    return r;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", a + i * n + j);
    printf("%d\n", det(a, n));
    return 0;
}


#include <cstdio>
#include <cmath>
const double eps = 1e-5;

double a[15][15];
int n;

bool equal(double x, double y)
{
    return fabs(x - y) < eps;
}

template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y, y = temp;
}

double determination()
{
    double r = 1;
    for (int i = 1; i <= n; i++)
    {
        if (equal(a[i][i], 0))
        {
            int j;
            for (j = i + 1; j <= n; j++)
                if (!equal(a[j][i], 0))
                    break;
            if (j == n + 1)
                return 0;
            r *= -1;
            for (int k = 1; k <= n; k++)
                swap(a[i][k], a[j][k]);
        }
        for (int j = i + 1; j <= n; j++)
        {
            double p = -(a[j][i] / a[i][i]);
            for (int k = i; k <= n; k++)
                a[j][k] += p * a[i][k];
        }
    }
    for (int i = 1; i <= n; i++)
        r *= a[i][i];
    return r;
}

int regularize(double x)
{
    double y = fabs(x);
    return (x >= 0 ? 1 : -1) * int(y + 0.5);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lf", &a[i][j]);
    double result = determination();
    printf("%d\n", regularize(result));
    return 0;
}
*/