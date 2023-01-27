#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

//问题在于如何构建哈希，查询了一下可以用双哈希方法,对地址进行操作，需要用到指针
//利用链地址法也可避免哈希冲突
//A-Z,a-z，0-9一共62个，离他最近的更大的质数为67，查询得到mod 131冲突的可能最小。oi常用的mod为1e9+7
//问了问朋友可以用一个flag让题目变得简单
//不确定是不是爆了数据的问题，把素数缩小点
//发现问题了，把存字符串的数组和指针弄混了
//原来是scanf的问题，少了个百分号，怎么回事呢
const int base[2] = {67,131};
const int mod = 1e9+7;
bool flag1[mod],flag2[mod];
char ss[3002];


int hashfunction(char *str, int num)
{
    int length = strlen(str);
    long long value = 0;
    for (int i = 0; i < length; i++)
    {
        value = (value * base[num] + str[i]) % mod;
    }
    return int(value);

}

bool exist(int key1, int key2){
    return flag1[key1] && flag2[key2];
}

int main()
{
    int n, sum = 0;
    cin >> n;

    while (n--)
    {
        scanf("%s", ss);
        int key1 = hashfunction(ss,0);
        int key2 = hashfunction(ss,1);
        if(!exist(key1,key2))
            {
                flag1[key1] = 1;
                flag2[key2] = 1;
                sum +=1;
            }
    
    }
    printf("%d",sum);
    return 0;
}


/*
reference:
https://blog.csdn.net/Mikchy/article/details/103995537
https://blog.csdn.net/weixin_45741872/article/details/108386984
*/
