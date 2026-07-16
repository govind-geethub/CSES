#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll missingCoinSum(ll n, vector<ll> &v)
{
    // mini missing sum will be +1 than every sum maintained
    ll missing = 1;
    sort(v.begin(), v.end());

    for(ll i=0; i<n; i++)
    {
        if(v[i] > missing) return missing;
        missing += v[i];
    }
    return missing;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << missingCoinSum(n,v) << endl;
    return 0;
}