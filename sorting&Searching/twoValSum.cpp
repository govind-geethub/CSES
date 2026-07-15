#include<bits/stdc++.h>
using namespace std;
#define ll long long

void twoValSum(ll n, ll x, vector<ll> &v)
{
    // {ele, ind} pair
    vector<pair<ll,ll>> temp(n);
    for(ll i=0; i<n; i++)
    {
        temp[i].first = v[i];
        temp[i].second = i+1;
    }

    sort(temp.begin(), temp.end());
    ll l = 0, r = n-1;
    while(l < r)
    {
        ll target = temp[l].first + temp[r].first;
        if(target == x)
        {
            cout << temp[l].second << " " << temp[r].second << endl;
            return;
        }
        else if(target > x) r--;
        else l++;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    ll n,x;
    cin >> n >> x;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    twoValSum(n,x,v);
    return 0;
}