#include<bits/stdc++.h>
using namespace std;
#define ll long long

// left of n/2 has 1 bit less for each n/2 from right side
ll countingBits(ll n, unordered_map<ll,ll> &mpp)
{
    if(n == 0) return 0;

    if(mpp[n]) return mpp[n];

    // for n = odd
    // f(n) = 2*f(n/2) + (n/2)+1
    if(n % 2) return mpp[n] = 2 * countingBits(n/2,mpp) + (n/2) + 1;

    // for n = even
    // f(n) = f(n/2-1) + f(n/2) + n/2
    else return mpp[n] = countingBits((n/2)-1, mpp) + countingBits(n/2, mpp) + n/2;
}

int main()
{
    ll n;
    cin >> n;

    unordered_map<ll,ll> mpp;
    cout << countingBits(n, mpp) << endl;
    return 0;
}