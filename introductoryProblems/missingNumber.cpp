#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll missingNumber(ll n, vector<ll> &v)
{
    ll ans = 0;
    for(ll i=1; i<=n; i++) ans = ans ^ i;

    for(ll i=0; i<v.size(); i++) ans = ans ^ v[i];
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n-1; i++) cin >> v[i];

    cout << missingNumber(n,v) << endl;
    return 0;
}