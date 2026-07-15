#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maxSubarrSum(ll n, vector<ll> &v)
{
    ll sum = 0;
    ll maxSum = 0;

    for(ll i=0; i<n; i++)
    {
        sum += v[i];
        if(sum < 0) sum = 0;
        else maxSum = max(maxSum, sum);
    }

    ll maxi = *max_element(v.begin(), v.end());
    if(maxSum == 0) return maxi;
    
    return maxSum;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    cout << maxSubarrSum(n,v) << endl;
    return 0;
}