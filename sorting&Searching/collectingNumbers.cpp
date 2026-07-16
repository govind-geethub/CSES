#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll collectingNumbers(ll n, vector<ll> &v)
{
    // min 1 round to check for 1...N
    ll rounds = 1;
    vector<ll> pos(n+1);
    for(ll i=0; i<n; i++) pos[v[i]] = i;

    // if 3's index is greater than 2 then it will allways take extra round to calc
    // similarly for all numbers
    for(ll i=1; i<n; i++)
    {
        if(pos[i] > pos[i+1]) rounds++;
    }
    return rounds;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << collectingNumbers(n,v) << endl;
    return 0;
}