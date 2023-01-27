#include<iostream>
#include<cstdio>
#include<cstring>
const int N = 710;
//感觉这题对我来说有点难搞
//已知c++中的字符串是使用null字符'\0'终止的dim 1字符数组
//从倒数第二位开始加,按照竖式加法，注意进位和最高位进位问题
char str1[N], str2[N], *result;
int m,n;
char* add_two_string(char *p, char *q)
// p和q分别为指向str1和str2的指针，函数返回一个指向字符串“和”的指针
{
    int len_p = strlen(p);
    int len_q = strlen(q);
    int len_s = 0;
    char *s = new char[N];
    for (int i = 0; i < 700; i++ )
        s[i] = '0';
    for (int i = 0; i< 700; i++)
    {
        int x,y;
        if (i < len_p)
            x = p[i] - '0';
        else
            x = 0;
        
        if (i < len_q)
            y = q[i] - '0';
        else
            y = 0;
        
        int z = s[i] - '0';
        int w = x + y + z;
        s[i] = '0' + w % 10, s[i+1] = '0' + w/10;
        if (s[i] != '0')
            len_s = i + 1;

    }
    s[len_s] = '\0';
    return s;
}

int main()
{
    scanf("%d%d%s%s", &m, &n, str1, str2);
    printf("%s\n", result = add_two_string(str1,str2));
    delete[] result;
    return 0;
}