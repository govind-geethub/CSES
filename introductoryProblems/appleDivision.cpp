#include<bits/stdc++.h>
using namespace std;
#define ll long long

// check every | x - (sum - x) | = (sum - 2x)
void solve(ll ind, ll sum, ll &ans, vector<ll> &v, ll totalSum)
{
    // out of bounds base case
    if(ind == v.size())
    {
        ans = min(ans, abs(totalSum - 2*sum));
        return;
    }

    // choose and move
    solve(ind+1,sum+v[ind],ans,v,totalSum);

    // not choose and move
    solve(ind+1,sum,ans,v,totalSum);
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    ll totalSum = 0;
    for(ll i=0; i<n; i++) totalSum += v[i];

    ll ans = LLONG_MAX;
    solve(0,0,ans,v,totalSum);
    
    cout << ans << endl;
    return 0;
}