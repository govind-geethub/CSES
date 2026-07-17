#include<bits/stdc++.h>
using namespace std;
#define ll long long

void josephusProblem1(ll n)
{
    queue<ll> q;
    for(ll i=1; i<=n; i++) q.push(i);

    while(!q.empty())
    {
        q.push(q.front());
        q.pop();

        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    ll n;
    cin >> n;

    josephusProblem1(n);
    return 0;
}