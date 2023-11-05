#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define N 101
#define C 50001

int dp[C], a[N];
int w[N], v[N];
int c,y,n,d;

int main()
{
    cin>>n;

    while (n--)
    {
        cin>>c>>y>>d;

        for (int i=1; i<=d; i++)
        {
            cin>>w[i]>>v[i];
            w[i]/=1000;
        }

        while (y--)
        {
            int m=c/1000;

            memset (dp, 0, sizeof (dp));

            for (int i=1; i<=d; i++)
                for (int j=w[i]; j<=m; j++)
                    dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
            
            c+=dp[m];
        }

        cout<<c<<endl;
    }
    return 0;
}