#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll playlist(ll n, vector<ll> &v)
{
    ll ans = 1;
    set<ll> st;
    
    // two-pointer
    ll l = 0;
    for(ll r=0; r<n; r++)
    {
        // erase until the duplicate is removed from the set
        while(st.find(v[r]) != st.end())
        {
            st.erase(v[l]);
            l++;
        }
        st.insert(v[r]);
        ans = max(ans, (r-l+1));
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << playlist(n,v) << endl;
    return 0;
}