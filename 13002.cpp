#include<iostream>
using namespace std;
//本题可以用桶排序来做

int a[1010];

int main()
{
    int n;
    cin >> n;
    int num[n];
    // for (int i = 0; i < 1011; i++)
    //     a[i] = 0;
    for (int i = 0; i < n; i++ )
        {
        cin >> num[i];

        }

    for (int i = 0; i < n; i++)
        for (int j = 1; j < 1001; j++)
        {
            if (num[i] == j)
            {
                a[j] = j;
                break;            
            }
        }
    int count = 0;
    for (int i = 0; i < 1010; i++)
        {
            if(a[i] != 0)
                count += 1;        
        }
    cout << count << endl;
    for (int i = 0; i < 1010; i++)
        //cout << a[i];
        {
            if(a[i] != 0)
        {
            cout << a[i] << " ";

        }
        }
    return 0;
}