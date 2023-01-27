#include<iostream>
#include<cstdio>

using namespace std;
//这个题个数不同但是其运算逻辑一样，所以使用函数模板是比较好的选择
//我们可以通过模拟出入栈过程在判断是否是合法的出栈序列,在出栈序列中，元素i之后所有比i小的元素之间必须是降序排列的

const int N = 1000010; 

int stack[N], top = 0;
int out[N];
int check(int n)
{
    int max = 0;
    top = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = max + 1; j <= out[i]; j++)
        {
            max = j;
            stack[top++] = j;
        }
        if (stack[--top] != out[i])
        
        return 0;
    }
    return 1;
}

int main()
{
    int T,n;
    scanf("%d", &T);
    while(T--)
    {
        cin >> n;
        for (int i = 1; i <=n; i++)
        {
            cin >> out[i];

        }
        if(check(n))
            printf("Yes\n");
        else
            printf("No\n");            
    }

    return 0;
}