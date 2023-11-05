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

inline void read(int &ax)
{
    register int x = 0, f = 1;
    register char ch = getchar();
    while (ch < 48 || ch>57)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= 48 && ch <= 57)
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    ax = x * f;
}

inline void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }

    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

struct node
{
    int num,cost;
};

node operator+(node aa, node bb)
{
    return (node){aa.num+bb.num,aa.cost+bb.cost};
}

bool operator<(node aa, node bb)
{
    return (aa.num!=bb.num?aa.num<bb.num:aa.cost>bb.cost);
}

#define N 101
#define M 1001
#define L 501

int m,l,n;
int v[N],w[N];
node d[M][L];

int main()
{
    read (m); read (l); read (n);

    for (int i=1; i<=n; i++)
        read (v[i]), read (w[i]);

    for (int i=1; i<=n; i++)
        for (int j=m; j>=v[i]; j--)
            for (int k=l; k>=w[i]; k--)
                d[j][k]=max(d[j][k], d[j-v[i]][k-w[i]]+(node){1, w[i]});
    
    cout<<d[m][l].num<<" "<<l-d[m][l].cost<<endl;
    return 0;
}