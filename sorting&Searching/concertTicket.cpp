#include<bits/stdc++.h>
using namespace std;
#define ll long long

void concertTicket(ll m, ll n, vector<ll> &t, vector<ll> &p)
{
    multiset<ll> price;
    for(auto it : t) price.insert(it);

    for(auto it : p)
    {
        auto ind = price.upper_bound(it);
        if(ind == price.begin()) cout << -1 << endl;
        else
        {
            ind--;
            cout << *ind << endl;
            price.erase(ind);
        }
    }
}

int main()
{
    ll m,n;
    cin >> m >> n;

    vector<ll> t(m);
    for(ll i=0; i<m; i++) cin >> t[i];

    vector<ll> p(n);
    for(ll i=0; i<n; i++) cin >> p[i];

    concertTicket(m,n,t,p);
    return 0;
}