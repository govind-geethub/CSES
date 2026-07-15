#include<bits/stdc++.h>
using namespace std;
#define ll long long

static bool customComp(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return a.second < b.second;
}

ll movieTicket(ll n, vector<pair<ll,ll>> &v)
{
    ll count = 1;
    // sort with movie ending at least time
    sort(v.begin(), v.end(), customComp);

    ll start = v[0].first;
    ll end = v[0].second;
    for(ll i=1; i<n; i++)
    {
        if(end <= v[i].first) 
        {
            count++;
            start = v[i].first;
            end = v[i].second;
        }
    }
    return count;
}

int main()
{
    ll n;
    cin >> n;

    vector<pair<ll,ll>> v(n);
    for(ll i=0; i<n; i++) cin >> v[i].first >> v[i].second;

    cout << movieTicket(n,v) << endl;
    return 0;
}