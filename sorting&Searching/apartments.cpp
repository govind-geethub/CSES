#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll apartments(ll n, ll m, ll k, vector<ll> &a, vector<ll> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll i = 0;
    ll j = 0;
    ll ans = 0;
    while(i < n && j < m)
    {
        if(abs(a[i]-b[j]) <= k)
        {
            i++; j++;
            ans++;
        }
        else if(b[j] < a[i] - k) j++;
        else i++;
    }
    return ans;
}

int main()
{
    ll n,m,k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin >> a[i];

    vector<ll> b(m);
    for(ll i=0; i<m; i++) cin >> b[i];

    cout << apartments(n,m,k,a,b) << endl;
    return 0;
}