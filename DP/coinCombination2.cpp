#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll coinCombination2(int n, int x, vector<ll>&v)
{
    int mod=1e9+7;
    int dp[n+1][x+1];

    for(int i=0; i<=n; i++) dp[i][0]=1; // many coins but sum 0 only 1 way

    dp[0][0]=1; // 1 way
    for(int sum=1; sum<=x; sum++) dp[0][sum]=0; // no coins and sum present 0 ways

    for(int i=1; i<=n; i++)
    {
        for(int sum=0; sum<=x; sum++)
        {
            if(sum==0) dp[i][sum]=1;
            else
            {
                int opt1=0;
                if(sum >= v[i]) opt1=dp[i][sum-v[i]];   // choosing the coin

                int opt2=dp[i-1][sum];  // not choosing

                dp[i][sum] = (opt1+opt2) % mod; // any 1 or other so added
            }
        }
    }

    return dp[n][x];
}

int main()
{
    int n,x;
    cin >> n >> x;

    vector<ll>v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    cout << coinCombination2(n,x,v) << endl;

    return 0;
}