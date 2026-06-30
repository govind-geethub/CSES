#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;

ll bitStrings(ll n)
{
    ll ans = 1;
    ll base = 2;
    while(n > 0)
    {
        if(n % 2) ans = (ans * base) % mod;

        base = (base * base) % mod;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    cout << bitStrings(n) << endl;
    return 0;
}