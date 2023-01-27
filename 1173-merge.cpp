#include<iostream>
using namespace std;

//分析此题，我们可以怎么做呢？根据中学学到的排序不等式，正序和>乱序和>逆序和
//所以此题转化为对我们这两个数组进行排序，排序完自然就有了结果
//果然冒泡会超时，那就换归并排序，想到可以优化空间，就不开数组c了
//还是不行，不是很熟悉归并，换快排试试
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
    long long x_max = 0,x_min = 0;
    long long N;
    cin >> N;
    long long a[N],b[N];
    for (long long i = 0; i < N; i++)
        cin >> a[i];
    for (long long i = 0; i < N; i++)
        cin >> b[i];
    mergeSort(a,N);
    mergeSort(b,N);


    for (long long i = 0; i < N; i++)
        {
        x_max += (long long)(a[i] * b[i]);
        x_min += (long long)(a[i] * b[N - i -1]);            
        }

    cout << x_max << ' '<< x_min;
    return 0; 

}