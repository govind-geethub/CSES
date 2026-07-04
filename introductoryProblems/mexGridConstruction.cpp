#include<bits/stdc++.h>
using namespace std;

// diagonal positions are 0
// a[i][j] = a[j][i]
// makes a XOR table
vector<vector<int>> mexTable(int n)
{
    vector<vector<int>> mex(n, vector<int> (n, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            mex[i][j] = i ^ j;
        }
    }
    return mex;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans = mexTable(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}