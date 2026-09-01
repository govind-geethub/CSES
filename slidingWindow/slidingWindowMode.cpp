#include<bits/stdc++.h>
using namespace std;
#define ll long long

// freq map
unordered_map<ll,ll> freq;

// freq, elements of that freq
map<ll,set<ll>> mpp;

void add(ll a)
{
    ll oldFreq = freq[a];
    if(oldFreq > 0)
    {
        mpp[oldFreq].erase(a);
        if(mpp[oldFreq].empty()) mpp.erase(oldFreq);
    }

    freq[a]++;
    mpp[freq[a]].insert(a);
}

void remove(ll a)
{
    ll oldFreq = freq[a];
    mpp[oldFreq].erase(a);

    if(mpp[oldFreq].empty()) mpp.erase(oldFreq);
    freq[a]--;

    if(freq[a] == 0) freq.erase(a);
    else mpp[freq[a]].insert(a);
}

void slidingWindowMode(ll n, ll k, vector<ll> &v)
{
    
    for(ll i=0; i<k; i++) add(v[i]);
    cout << *mpp.rbegin()->second.begin();

    for(ll i=k; i<n; i++)
    {
        remove(v[i-k]);
        add(v[i]);

        ll mode = *mpp.rbegin()->second.begin();
        cout << " " << mode;
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
    
    slidingWindowMode(n,k,v);
    cout << endl;

    return 0;
}