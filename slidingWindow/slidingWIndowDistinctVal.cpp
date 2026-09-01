#include<bits/stdc++.h>
using namespace std;
#define ll long long

void slidingWindowDistinctVal(ll n, ll k, vector<ll> &v)
{
    unordered_map<ll,ll> mpp;
    mpp.reserve(2*k);
    mpp.max_load_factor(0.7);

    for(ll i=0; i<k; i++) mpp[v[i]]++;
    cout << mpp.size();

    for(ll i=k; i<n; i++)
    {
        ll old = v[i-k];
        mpp[old]--;
        if(mpp[old] == 0)mpp.erase(old);

        mpp[v[i]]++;
        cout << " " << mpp.size();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin >> n >> k;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];
    
    slidingWindowDistinctVal(n,k,v);
    cout << endl;

    return 0;
}