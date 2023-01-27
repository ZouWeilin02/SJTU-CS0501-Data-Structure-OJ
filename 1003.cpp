#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//此题使用贪心算法解决

template<class elemType>
void merge(elemType a[], long long low, long long  mid, long long high)
{
    long long i,j,k;
    elemType *c;

    c = new elemType[high - low + 1];
    i = low;
    j = mid + 1;
    k = 0;

    while ((i <= mid) && (j <= high))
    {
        if (a[i] <= a[j])
        {
            c[k] = a[i];
            i += 1;
        }
        else
        {
            c[k] = a[j];
            j += 1;
        }
        k += 1;
    }

    while( i <= mid)
    {
        c[k] = a[i];
        i += 1;
        k += 1;
    }

    while( j <= high)
    {
        c[k] = a[j];
        j += 1;
        k += 1;
    }
    for (i = 0; i < high - low + 1; i++)
        a[i + low] = c[i];
        delete []c;
}
template <class elemType>
void mergeSort(elemType a[], long long low, long long high)
{
    long long mid;

    if (low >= high) return;
    mid = (low + high) /2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

template <class elemType>
void mergeSort(elemType a[],long long n)
{
    mergeSort(a, 0 , n-1);
}


int main()
{
    long long n,t,k;
    cin >> n >> t >> k;
    long long si[n];
        
    for (int i = 0; i < n; i++)
        cin >> si[i];
    mergeSort(si, n);
    // for (int i = 0; i < n; i++)
    //     cout << si[i] << " ";
    int count = 0;
    for (int i = 0; i < n; i++)
        {
        if (si[i] < k - t)
            {
                count += 1;
                t += si[i];
            }

        }
    int score = (int)(((count * 100)  + (n - count) * 10.00) / n);
    cout << score;    
    // cout << n << t << k;
    return 0;

}









