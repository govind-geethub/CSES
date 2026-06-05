#include<bits/stdc++.h>
using namespace std;

int dp[5001][5001];
int solve(int i, int j, string &s, string &p)
{
    // base case
    if(i==s.length()) return p.length()-j;
    if(j==p.length()) return s.length()-i;

    // already calculated so return it
    if(dp[i][j] != -1) return dp[i][j];

    // if both are already same
    if(s[i] == p[j]) return dp[i][j]= solve(i+1,j+1,s,p);

    int opt1= 1+ solve(i,j+1,s,p); // add
    int opt2= 1+ solve(i+1,j,s,p); // remove
    int opt3= 1+ solve(i+1,j+1,s,p); // replace

    return dp[i][j] = min(opt1, min(opt2,opt3));    // minimum of the 3
}

int main()
{
    string s,p;
    cin >> s >> p;

    memset(dp,-1, sizeof dp);
    cout << solve(0,0,s,p) << endl;
    return 0;
}