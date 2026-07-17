#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll distinctSubarr(ll n, vector<ll> &v)
{
    ll l = 0;
    ll count = 0;
    set<ll> st;

    for(ll r=0; r<n; r++)
    {
        while(st.count(v[r]))
        {
            st.erase(v[l]);
            l++;
        }
        st.insert(v[r]);

        // r-l+1 gives len of subArr but when all distinct
        // also gives count of distinct subArr
        count += (r-l+1);
    }
    return count;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << distinctSubarr(n,v) << endl;
    return 0;
}