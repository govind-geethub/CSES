#include <bits/stdc++.h>
using namespace std;
#define ll long long

void roomAllocate(ll n, vector<pair<ll,ll>> &time)
{
    vector<pair<pair<ll,ll>, ll>> customer;
    for (ll i = 0; i < n; i++) customer.push_back({time[i], i});
    sort(customer.begin(), customer.end());

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> ans(n);
    ll rooms = 0;

    for (ll i = 0; i < n; i++)
    {
        ll arrival = customer[i].first.first;
        ll departure = customer[i].first.second;
        ll ind = customer[i].second;

        if (!pq.empty() && pq.top().first < arrival)
        {
            ll room = pq.top().second;
            pq.pop();

            ans[ind] = room;
            pq.push({departure, room});
        }
        else
        {
            rooms++;
            ans[ind] = rooms;
            pq.push({departure, rooms});
        }
    }

    cout << rooms << endl;
    for (ll i = 0; i < n; i++) cout << ans[i] << " ";
}

int main()
{
    ll n;
    cin >> n;

    vector<pair<ll,ll>> time(n);
    for (ll i = 0; i < n; i++) cin >> time[i].first >> time[i].second;

    roomAllocate(n, time);
    return 0;
}
