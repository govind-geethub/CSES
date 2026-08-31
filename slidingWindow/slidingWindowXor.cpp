#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll slidingWindowXor(ll n, ll k, ll x, ll a, ll b, ll c)
{
    vector<ll> nums;
    ll i=0;
    while(i < n)
    {
        nums.push_back(x);
        x = (a*x + b) % c;
        i++;
    }

    ll ans = 0;
    for(ll i=0; i<k; i++) ans ^= nums[i];

    ll cpy = ans;
    for(ll i=k; i<n; i++)
    {
        cpy ^= nums[i-k];
        cpy ^= nums[i];
        ans ^= cpy;
    }
    return ans;
}

int main()
{
    ll n,k;
    cin >> n >> k;

    ll x,a,b,c;
    cin >> x >> a >> b >> c;

    cout << slidingWindowXor(n,k,x,a,b,c) << endl;
    return 0;
}