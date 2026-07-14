#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll restaurantCustomers(ll n, vector<pair<ll,ll>> &v)
{
    sort(v.begin(), v.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    ll count = 0;
    for(ll i=0; i<n; i++)
    {
        ll arrival = v[i].first;
        ll depart = v[i].second;
        
        // depart of prevCustomer < arrival so he exits
        while(!pq.empty() && pq.top() < arrival) pq.pop();

        pq.push(depart);
        count = max(count, (ll)pq.size());
    }
    return count;
}

int main()
{
    ll n;
    cin >> n;

    vector<pair<ll,ll>> v(n);
    for(ll i=0; i<n; i++) cin >> v[i].first >> v[i].second;

    cout << restaurantCustomers(n,v) << endl;
    return 0;
}