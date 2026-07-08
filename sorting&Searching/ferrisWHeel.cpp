#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ferrisWheel(ll n, ll w, vector<ll> &v)
{
    sort(v.begin(), v.end());

    ll i=0, j=n-1;
    ll req = 0;
    while(i <= j)
    {
        if(v[i] + v[j] <= w)
        {
            i++;
            j--;
        }
        else j--;
        req++;
    }
    return req;
}

int main()
{
    ll n,w;
    cin >> n >> w;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << ferrisWheel(n,w,v) << endl;
    return 0;
}