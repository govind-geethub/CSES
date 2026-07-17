#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll towers(ll n, vector<ll> &v)
{
    multiset<ll> st;
    for(ll i=0; i<n; i++)
    {
        // remove the top cube
        auto it = st.upper_bound(v[i]);

        if(it != st.end()) st.erase(it);
        // insert the small cube on that top
        st.insert(v[i]);
    }
    return st.size();
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << towers(n,v) << endl;
    return 0;
}