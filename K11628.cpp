#include <iostream>
#include <cmath>

using namespace std;

#define N 101
#define C 1001

int t,n;
int w[N],v[N],dp[C];

int main()
{
    cin>>t>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    
    for (int i=1;i<=n;i++)
        for (int j=w[i];j<=t;j++)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    
    cout<<dp[t];
    return 0;
}