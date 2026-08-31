#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll slidingWindowSum(ll n, ll k, ll x, ll a, ll b, ll c)
{
    deque<pair<ll,ll>> dq;
    ll ans = 0;
    for(ll i=0; i<n; i++)
    {
        // out of the window
        while(!dq.empty() && dq.front().second <= i - k) dq.pop_front();

        // can't be minimum
        while(!dq.empty() && dq.back().first >= x) dq.pop_back();

        dq.push_back({x,i});

        // window size
        if(i >= k-1) ans ^= dq.front().first;

        x = (a*x + b) % c;
    }
    return ans;
}

int main()
{
    ll n,k;
    cin >> n >> k;

    ll x,a,b,c;
    cin >> x >> a >> b >> c;

    cout << slidingWindowSum(n,k,x,a,b,c) << endl;
    return 0;
}