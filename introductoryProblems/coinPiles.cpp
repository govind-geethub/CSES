#include<bits/stdc++.h>
using namespace std;
#define ll long long

string coinPiles(ll a, ll b)
{
    if((a + b) % 3) return "NO";

    ll diff = abs(a - b);
    if(diff > max(a,b) / 2) return "NO";
    return "YES";
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll a,b;
        cin >> a >> b;
        cout << coinPiles(a,b) << endl;
    }

    return 0;
}