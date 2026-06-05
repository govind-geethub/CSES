#include<bits/stdc++.h>
using namespace std;

// distinct ways  2,2,5 & 2,5,2 are two different ways
int coinCombination1(int n, int x, vector<int>&v)
{
    vector<int>dp(x+1, 0);
    int mod=1e9+7;

    dp[0]=1;    // base case
    for(int i=1; i<=x; i++)
    {
        for(auto coin : v)
        {
            if(coin > i) continue;   // avoid case
            dp[i] = (dp[i] + dp[i-coin]) % mod;     // n ways to reach 0
        }
    }

    return dp[x];
}

int main()
{
    int n,x;
    cin >> n >> x;

    vector<int>v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    cout << coinCombination1(n,x,v) << endl;
    return 0;
}