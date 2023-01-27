#include<iostream>
using namespace std;
const int N = 10010;
int a[N];

int main()
{
    int n;
    cin>>n;
    int live_monkey = 0;
    for(int i = 1; i < n; i++)
        cin>>a[i];
    for(int i = 2; i <= n; i++)
        (live_monkey += a[n-i+1]) %= i;
    cout<<live_monkey + 1;
    return 0;
}