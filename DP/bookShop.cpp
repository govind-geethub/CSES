// maximize n(pages) with cost x
#include<bits/stdc++.h>
using namespace std;

int bookShop(int n, int x, vector<int>&cost, vector<int>&page)
{
    vector<vector<int>>dp(n+1, vector<int>(x+1, 0));    // also defines the base case

    for(int i=1; i<=n; i++)
    {
        for(int money=0; money<=x; money++)
        {
            int opt1= dp[i-1][money];   // not choosing the ith book
            
            int opt2= 0;
            if(money >= cost[i]) opt2=page[i]+dp[i-1][money-cost[i]];   // choosing, pages++ & cost-- 

            dp[i][money]=max(opt1, opt2);
        }
    }
    return dp[n][x];
}

int main()
{
    int n,x;
    cin >> n >> x;

    vector<int>cost(n+1), page(n+1);

    for(int i=1; i<=n; i++) cin >> cost[i];
    for(int i=1; i<=n; i++) cin >> page[i];

    cout << bookShop(n,x,cost,page) << endl;
    return 0;
}