#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll stickLength(ll n, vector<ll> &v)
{
    ll cost = 0;
    sort(v.begin(), v.end());

    ll stickLen = v[n/2];
    for(ll i=0; i<n; i++) cost += abs(stickLen - v[i]);
    return cost;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << stickLength(n,v) << endl;
    return 0;
}