#include<iostream>
using namespace std;

//分析此题，我们可以怎么做呢？根据中学学到的排序不等式，正序和>乱序和>逆序和
//所以此题转化为对我们这两个数组进行排序，排序完自然就有了结果
//果然冒泡会超时，那就换归并排序，想到可以优化空间，就不开数组c了
template <class elemType>
void bubbleSort(elemType a[], int n)
{
    int i,j;
    elemType tmp;
    bool changeFlag = true;

    for (j = n-1; j>0; j--)
    {
        if (!changeFlag) break;

        changeFlag = false;
        for (i = 0;i < j; i++)
            if(a[i] > a[i+1])
            {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                changeFlag = true;
            }
    }
}

template<class elemType>
void bubbleSort_inversion(elemType a[], int n)
{
    int i,j;
    elemType tmp;
    bool changeFlag = true;

    for (j = n-1; j>0; j--)
    {
        if (!changeFlag) break;

        changeFlag = false;
        for (i = 0;i < j; i++)
            if(a[i] < a[i+1])
            {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                changeFlag = true;
            }
    }
}

int main()
{
    long long x_max = 0,x_min = 0;
    int N;
    cin >> N;
    int a[N],b[N],c[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        {
        cin >> b[i];
        c[i] = b[i];
        }
    bubbleSort(a,N);
    bubbleSort(b,N);
    bubbleSort_inversion(c,N);

    for (int i = 0; i < N; i++)
        {
        x_max += (long long)(a[i] * b[i]);
        x_min += (long long)(a[i] * c[i]);            
        }

    cout << x_max << ' '<< x_min;
    return 0; 

}