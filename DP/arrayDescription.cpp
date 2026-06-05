#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// use long long to avoid integer overflow
int arrayDescription(int n, int m, vector<int>&v)
{
    int ans=0;
    int mod=1e9+7;
    vector<vector<ll>>dp(n+2, vector<ll>(m+2, 0)); // n+2 -> avoid the edge cases of out of bound

    for(int i=1; i<=n; i++)
    {
        for(int x=1; x<=m; x++)
        {
            if(i == 1)
            {
                // base case
                if(v[i]==0 || v[i]==x) dp[i][x]=1;
                else dp[i][x]=0;
            }
            else
            {
                // 3 ways to fulfill the criteria : fill with x-1  x  x+1
                if(v[i]==0 || v[i]==x) dp[i][x] = (dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x+1]) % mod;
                else dp[i][x]=0;
            }
        }
    }

    for(int x=1; x<=m; x++) ans = (ans+dp[n][x]) % mod;     // ans with all the ways to compute
    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int>v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    cout << arrayDescription(n,m,v) << endl;
    return 0;
}