#include<iostream>
#include<cstdio>
using namespace std;

const int N = 10005;
int main()
{
    int staticlookuptable[N];
    int n,m, times = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> staticlookuptable[i];
    cin >> m;
    for (int i = 1,j; i <= m; i++)
    {
        int num;
        scanf("%d", &num);
        for (j = 1; j <= n; j++)
            
               
            if (staticlookuptable[j] == num) break;
            if (j == n + 1 )
                times += n;
            else   
            {
                times += j;
                int temp = staticlookuptable[j];
                for(int k = j; k >= 2; k--)
                staticlookuptable[k] = staticlookuptable[k-1];
                staticlookuptable[1] = temp;
            }

            
   
    }
    printf("%d", times);
    return 0; 
}