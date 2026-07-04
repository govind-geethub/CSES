#include<bits/stdc++.h>
using namespace std;

int n;

// next knight position calc.
vector<int> dr = {2,2,-2,-2,1,1,-1,-1};
vector<int> dc = {1,-1,1,-1,2,-2,2,-2};

// BFS to calculate DFS has repeated paths
//no need relax the element like DFS everytime
void knightMovesGrid(int n, vector<vector<int>> &ans)
{
    queue<pair<int,int>> q;

    q.push({0,0});
    ans[0][0] = 0;

    while(!q.empty())
    {
        auto ind = q.front();
        q.pop();

        int row = ind.first;
        int col = ind.second;

        for(int i=0; i<8; i++)
        {
            int adjR = row + dr[i];
            int adjC = col + dc[i];

            if(adjR >= 0 && adjR < n && adjC >= 0 && adjC < n)
            {
                if(ans[adjR][adjC] == -1)
                {
                    ans[adjR][adjC] = ans[row][col] + 1;
                    q.push({adjR, adjC});
                }
            }
        }
    }
}

int main()
{
    cin >> n;

    vector<vector<int>> ans(n, vector<int>(n, -1));
    knightMovesGrid(n,ans);

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