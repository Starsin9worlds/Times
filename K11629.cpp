#include <iostream>

using namespace std;

#define N 5001
#define C 6001

int n,c;
long long w[N],v[N],dp[C];

int main()
{
    cin>>n>>c;

    int tot=0;
    int tw,tv,ts;

    for (int i=1;i<=n;i++)
    {
        cin>>tv>>tw>>ts;

        int num = min(c/tv,ts);
        for (int j=1;j<num;j<<=1)
        {
            tot++;
            num-=j;

            v[tot]=tw*j;
            w[tot]=tv*j;
        }

        ++tot;
        v[tot]=num*tw;
        w[tot]=num*tv;
    }

    for (int i=1;i<=tot;i++)
        for (int j=c;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    
    cout<<dp[c];
    return 0;
}