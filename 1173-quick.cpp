#include<iostream>
using namespace std;

//分析此题，我们可以怎么做呢？根据中学学到的排序不等式，正序和>乱序和>逆序和
//所以此题转化为对我们这两个数组进行排序，排序完自然就有了结果
//果然冒泡会超时，那就换归并排序，想到可以优化空间，就不开数组c了
//还是不行，不是很熟悉归并，换快排试试,仍然参考课本代码
//算法是没错的啊，所以问题是出在数据范围吗？把int换long long碰下吧
template<class elemType>
void quickSort(elemType a[], long long start, long long end) 
{
	long long i, j, hole;
	elemType temp;
	if (end <= start) return;
	temp = a[start];
	hole = start;
	i = start;
	j = end;
	while (i < j) 
    {
		while ((j > i) && (a[j] >= temp)) j--;
		if (i == j) break;
		a[hole] = a[j];
		hole = j;
		while ((i < j) && (a[i] < temp)) i++;
		if (j == i) break;
		a[hole] = a[i];
		hole = i;
	}
	a[hole] = temp;
	quickSort(a, start, hole - 1);
	quickSort(a, hole + 1, end);
}

template<class elemType>
void quickSort(elemType a[], long long n)
{
	quickSort(a, 0, n - 1);
}

int main()
{
    long long x_max = 0,x_min = 0;
    long long N;
    cin >> N;
    long long a[N],b[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];
    quickSort(a,N);
    quickSort(b,N);


    for (int i = 0; i < N; i++)
        {
        x_max += (long long)(a[i] * b[i]);
        x_min += (long long)(a[i] * b[N - i -1]);            
        }

    cout << x_max <<" "<< x_min;
    return 0; 

}