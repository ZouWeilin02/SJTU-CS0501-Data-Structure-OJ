#include<iostream>
#include<cstdio>
#include<cstdlib>
//可以用堆来实现
const int N = 20010;
void quicksqeue(int a[], int length, int r);

int main()
{
    int n, a[N], i;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)//读取每一堆的果子数
    {
        scanf("%d", &a[i]);
    }
    quicksqeue(a,1,n);
    long num = 0;
    int tmp1 = 0, tmp2 = 0, j, k, l;
    i = 1;
    while(i != n)
    {
        tmp1 = a[i]; i++;
        tmp2 = a[i]; i++;
        l = tmp1 + tmp2;
        num += l;
        for(k = i; k <= n; k++)
        {
            if(a[k] >= l) break;
        }
        for (j = n + 1; j > k; j--)
        {
            a[j] = a[j - 1];
        }
        a[k] = l;
        n++;
    } 
    printf("%ld\n", num);
    return 0;
}

void quicksqeue(int a[], int length, int r)
{
    int i = length, j = r, key = a[length];
    if (length >= r) return;
    while(i < j)
    {
        while(i < j && a[j] >= key)
        {
            j--;
        }
        a[i] = a[j];
        while (i < j && a[i] <= key)
        {
            i++;
        }
        a[j] = a[i];

    }
    a[i] = key;
    quicksqeue(a, length, i - 1 );
    quicksqeue(a, i + 1, r);
}