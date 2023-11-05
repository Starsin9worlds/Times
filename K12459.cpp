#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define N 101
#define T 101
#define M 10001

int t,n,m;
int p[T][N],d[M];

int main()
{
    cin>>t>>n>>m;

    for (int i=1; i<=t; i++)
        for (int j=1; j<=n; j++)
            cin>>p[i][j];

    for (int k=1; k<t; k++)
    {
        memset (d, 0, sizeof (d));

        for (int i=1; i<=n; i++)
            for (int j=p[k][i]; j<=m; j++)
                d[j]=max(d[j], d[j-p[k][i]]+p[k+1][i]-p[k][i]);

        m+=d[m];
    }

    cout<<m<<endl;
    return 0;
}