#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll slidingWindowSum(ll n, ll k, ll x, ll a, ll b, ll c)
{
    vector<ll> temp;
    temp.push_back(x);

    ll i = 1;
    while(i < n)
    {
        x = (a*temp.back() + b) % c;
        temp.push_back(x);
        i++;
    }

    ll sum = 0;
    for(ll i=0; i<k; i++) sum += temp[i];
    
    ll ans = sum, cpy = sum;
    for(ll i=k; i<n; i++)
    {
        cpy -= temp[i-k];
        cpy += temp[i];
        ans = ans ^ cpy;
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