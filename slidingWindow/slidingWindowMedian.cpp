#include<bits/stdc++.h>
using namespace std;
#define ll long long

multiset<ll> low, high;
void balance()
{
    while(low.size() > high.size() + 1) 
    {
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it);
    }

    while(low.size() < high.size())
    {
        auto it = high.begin();
        low.insert(*it);
        high.erase(it);
    }
}

void add(ll a)
{
    if(low.empty() || a <= *low.rbegin()) low.insert(a);
    else high.insert(a);
    balance();
}

void remove(ll a)
{
    auto it = low.find(a);
    if(it != low.end()) low.erase(it);

    else 
    {
        it = high.find(a);
        high.erase(it);
    } 
    balance();
}

double getMedian()
{
    if(low.size() > high.size()) return *low.rbegin();
    return ((double)*low.rbegin() + (double)*high.begin()) / 2;
}

vector<double> slidingWindowMedian(ll n, ll k, vector<ll> &v)
{
    vector<double> ans;
    for(ll i=0; i<k; i++) add(v[i]);

    ans.push_back(getMedian());

    for(ll i=k; i<n; i++)
    {
        remove(v[i-k]);
        add(v[i]);

        ans.push_back(getMedian());
    }
    return ans;
}

int main()
{
    ll n,k;
    cin >> n >> k;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    vector<double> ans = slidingWindowMedian(n,k,v);
    for(ll i=0; i<ans.size(); i++) cout << ans[i] <<  " ";
    return 0;
}