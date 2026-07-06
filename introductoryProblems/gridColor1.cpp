#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> ans;

void gridColor(int n, int m, vector<vector<char>> &v)
{
    string letter = "ABCD";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char original = v[i][j];
            for(char ch : letter)
            {
                if(ch == original) continue;
                if(i-1 >= 0 && ch == ans[i-1][j]) continue;
                if(j-1 >= 0 && ch == ans[i][j-1]) continue;
                ans[i][j] = ch;
                break;
            }
        }
    }

    // verify for impossible
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(ans[i][j] == v[i][j])
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }

            if(i-1 >= 0 && ans[i][j] == ans[i-1][j])
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
            if(j-1 >= 0 && ans[i][j] == ans[i][j-1])
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    ans.assign(n, vector<char>(m, '.'));

    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> v[i][j];
        }
    }

    gridColor(n,m,v);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}