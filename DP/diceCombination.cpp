#include<bits/stdc++.h>
using namespace std;
#define ll long long

// six ways to get to n
// after dice rolls we have 6 options
// it'll be either 1, 2.... or 6
ll diceCombination(int n)
{
    int mod=1e9+7;

    vector<ll>dp(n+1);
    dp[0]=1;    // 1 way to do to get 0 i.e. do nothing

    for(int i=1; i<=n; i++)
    {
        for(int x=1; x<=6; x++)
        {
            if(i<x) break;
            dp[i]=(dp[i]+dp[i-x]) % mod;
        }
        //cout << dp[i] << endl;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << diceCombination(n) << endl;

    return 0;
}