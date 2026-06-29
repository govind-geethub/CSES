#include<bits/stdc++.h>
using namespace std;

void permutations(int n)
{
    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }

    if(n <= 3) 
    {
        cout << "NO SOLUTION";
        return;
    }

    if(n == 4)
    {
        vector<int> ans = {2,4,1,3};
        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
        return;
    }
    
    vector<int> ans;
    for(int i=1; i<=n; i+=2) ans.push_back(i);
    for(int i=2; i<=n; i+=2) ans.push_back(i);

    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    permutations(n);
    return 0;
}