#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
void bfs(vector<vector<char>> &v, vector<vector<ll>> &vis, ll i, ll j)
{
    queue<pair<ll,ll>> q;
    q.push({i,j});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        ll row = it.first, col = it.second;
        vis[row][col] = 1;
        if(row+1 < n && !vis[row+1][col] && v[row+1][col] == '.') 
        {
            q.push({row+1, col});
            vis[row+1][col] = 1;
        }
        if(row-1 >= 0 && !vis[row-1][col] && v[row-1][col] == '.')
        {
            q.push({row-1, col});
            vis[row-1][col] = 1;
        }
        if(col+1 < m && !vis[row][col+1] && v[row][col+1] == '.')
        {
            q.push({row,col+1});
            vis[row][col+1] = 1;
        }
        if(col-1 >= 0 && !vis[row][col-1] && v[row][col-1] == '.')
        {
            q.push({row,col-1});
            vis[row][col-1] = 1;
        }
    }
}

ll countingRooms(ll n, ll m, vector<vector<char>> &v)
{
    vector<vector<ll>> vis(n, vector<ll> (m, 0));
    ll cnt = 0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(v[i][j] == '.' && !vis[i][j]) 
            {
                cnt++;
                bfs(v,vis,i,j);
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << countingRooms(n,m,v) << endl;
    return 0;
}