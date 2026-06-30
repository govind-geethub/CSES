#include<bits/stdc++.h>
using namespace std;
#define ll long long

// trailing depend on 2*5
// n(2s) is much greater n(5s) so we take number of 5s to calculate
ll trailingZeros(ll n)
{
    ll ans = 0;
    while(n > 0)
    {
        ans += (n/5);
        n = n/5;
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    cout << trailingZeros(n) << endl;
    return 0;
}