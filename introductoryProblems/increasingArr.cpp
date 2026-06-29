#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll increasingArr(ll n, vector<ll> &v)
{
    ll ans = 0;
    for(ll i=1; i<n; i++)
    {
        if(v[i] < v[i-1]) 
        {
            ans += (v[i-1] - v[i]);
            v[i] = v[i-1];
        }
        else continue;
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll>v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << increasingArr(n,v) << endl;
    return 0;
}