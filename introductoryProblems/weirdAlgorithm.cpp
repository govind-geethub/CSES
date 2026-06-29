#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> weirdAlgo(ll n)
{
    vector<ll> ans;
    while(n != 1)
    {
        ans.push_back(n);
        if(n % 2) n = 3*n + 1;
        else n = n/2;
    }

    ans.push_back(1);
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> ans = weirdAlgo(n);
    for(ll i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}