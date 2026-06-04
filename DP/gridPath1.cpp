#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gridPath1(int n, vector<vector<char>>&v)
{
    int mod=1e9+7;
    vector<vector<int>>grid(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i][j]=='.') grid[i][j]=0;
            else grid[i][j]=1;
        }
    }

    int dp[n][n];
    for(int i=n-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(i==n-1 && j==n-1) dp[i][j]= (grid[i][j]) ? 0 : 1;    // may be the bottom right be trap check
            else
            {
                int opt1= (j==n-1) ? 0 : dp[i][j+1];    // going right check
                int opt2= (i==n-1) ? 0 : dp[i+1][j];    // going down check

                dp[i][j]=(opt1 + opt2) % mod;

                if(grid[i][j]) dp[i][j]=0;  // trap path
            }
        }
    }
    return dp[0][0];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> v(n, vector<char>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << gridPath1(n,v) << endl;

    return 0;
}