#include<iostream>
#include<cmath>

using namespace std;

const int N =100010;

int main()
{
    int n;
    cin>>n;
    int a[N],b[N],c[N],d[N];
    for(int i=0; i<n; i++) 
        cin>>a[i];
    for(int i=0; i<n; i++) 
        cin>>b[i];
    //作差，获得新数组
    for(int i=0; i<n; i++)
        c[i] = a[i] - b[i];
    //获得差分数组
    for(int i=n-1; i>=1; i--)
        d[i] = c[i]-c[i-1];
    d[0] = c[0];
    long long res = 0, unres = 0,maxx = 0;
    for(int i=0; i<n; i++ )
    {
        if(d[i] >0)
            res += d[i];
        else
            unres -= d[i];

    }
    maxx = max(res,unres);
    cout<<maxx<<endl;
    return 0;

}