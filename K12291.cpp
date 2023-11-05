#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define ull unsigned long long
#define us unsigned short

#define N 105
#define C 50005

int n,c,v[N],w[N];
int d[C];

int main()
{
    cin>>n>>c;

    for (int i=1; i<=n; i++)
        cin>>w[i]>>v[i];

    memset (d, 0x3f, sizeof (d));

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=c; j++)
        {
            if (w[i]<j)
                d[j]=min (d[j], d[j-w[i]]+v[i]);

            else d[j]=min (d[j], v[i]);
        }
    }

    cout<<d[c];

    return 0;
}