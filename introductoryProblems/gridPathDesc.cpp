#include<bits/stdc++.h>
using namespace std;

string path;
vector<vector<int>> vis(7, vector<int>(7,0));
int ans = 0;

bool inBound(int r, int c)
{
    return (r >= 0 && r < 7 && c >= 0 && c < 7);
}

void dfs(int r, int c, int step)
{
    if(r == 6 && c == 0 || step == 48)
    {
        if(r == 6 && c == 0 && step == 48) ans += 1;
        return;
    }

    // boxed in optimisation
    // up down can't left right free
    if((!inBound(r-1,c) || vis[r-1][c]) && (!inBound(r+1,c) || vis[r+1][c]))
    {
        if(inBound(r,c-1) && !vis[r][c-1] && inBound(r,c+1) && !vis[r][c+1]) return;
    }

    // left right can't up down free
    if((!inBound(r,c-1) || vis[r][c-1]) && (!inBound(r,c+1) || vis[r][c+1]))
    {
        if(inBound(r-1,c) && !vis[r-1][c] && inBound(r+1,c) && !vis[r+1][c]) return;
    }

    vis[r][c] = 1;

    // ? go all adirections if s[i] != ? go into that
    if(path[step] == '?' || path[step] == 'R')
    {
        if(inBound(r,c+1) && !vis[r][c+1]) dfs(r,c+1,step+1);
    }

    if(path[step] == '?' || path[step] == 'L')
    {
        if(inBound(r,c-1) && !vis[r][c-1]) dfs(r,c-1,step+1);
    }

    if(path[step] == '?' || path[step] == 'U')
    {
        if(inBound(r-1,c) && !vis[r-1][c]) dfs(r-1,c,step+1);
    }
    if(path[step] == '?' || path[step] == 'D')
    {
        if(inBound(r+1,c) && !vis[r+1][c]) dfs(r+1,c,step+1);
    }

    vis[r][c] = 0;  // all paths exhausted from r,c mark unvisited
}

int main()
{
    cin >> path;
    dfs(0,0,0);

    cout << ans << endl;
    return 0;
}