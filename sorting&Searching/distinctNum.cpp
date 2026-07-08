#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll distinctNum(ll n, vector<ll> &v)
{
    sort(v.begin(), v.end());
    ll count = 1;
    ll lastNum = v[0];

    for(ll i=1; i<n; i++)
    {
        if(lastNum == v[i]) continue;
        else
        {
            lastNum = v[i];
            count++;
        }
    }
    return count;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << distinctNum(n,v) << endl;
    return 0;
}