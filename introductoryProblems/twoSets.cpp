#include<bits/stdc++.h>
using namespace std;
#define ll long long

void twoSets(int n)
{
    ll sum = (ll)n;
    sum = sum * (ll)(n+1);
    sum = sum / 2;

    if(sum % 2) 
    {
        cout << "NO" << endl;
        return;
    }

    if(n % 2 == 0)
    {
        cout << "YES" << endl;
        vector<ll> v1, v2;
        ll l=1, r=n;
        ll count = 0;
        while(l < r)
        {
            if(count % 2 == 0)
            {
                v1.push_back(l);
                v1.push_back(r);
            }

            else
            {
                v2.push_back(l);
                v2.push_back(r);    
            }

            l++; r--;
            count++;
        }

        cout << v1.size() << endl;
        for(ll i=0; i<v1.size(); i++) cout << v1[i] << " ";
        cout << endl;

        cout << v2.size() << endl;
        for(ll i=0; i<v2.size(); i++) cout << v2[i] << " ";
        cout << endl;

        return;
    }

    cout << "YES" << endl;
    vector<ll> v1, v2;
    ll oddSum = 0, evenSum = 0;

    for(ll i=1; i<=n; i++)
    {
        if(i % 2)
        {
            v1.push_back(i);
            oddSum += i;
        }
        else
        {
            v2.push_back(i);
            evenSum += i;
        }
    }

    vector<ll> temp1 = v1;
    vector<ll> temp2 = v2;

    unordered_set<ll> st;
    for(ll a : temp1) st.insert(a);

    ll req = (oddSum - evenSum) / 2;
    if(st.find(req) != st.end())
    {
        temp2.push_back(req);

        st.erase(req);
        temp1.assign(st.begin(), st.end());

        cout << temp1.size() << endl;
        for(ll i=0; i<temp1.size(); i++) cout << temp1[i] << " ";
        cout << endl;

        cout << temp2.size() << endl;
        for(ll i=0; i<temp2.size(); i++) cout << temp2[i] << " ";
        cout << endl;

        return;
    }

    sort(v1.begin(), v1.end());
    ll l=0, r=v1.size()-1;
    while(l < r)
    {
        ll sum = (v1[l] + v1[r]);
        if(sum == 2*req) break;
        else if(sum > 2*req) r--;
        else l++;
    }
    // cout << req << endl;
    // cout << l << " " << r << endl;
    //cout << v1[l] << " " << v1[r] << endl;

    ll val1 = v1[l];
    ll val2 = v1[r];

    unordered_set<ll> s1;
    for(ll a : v1) s1.insert(a);

    s1.erase(v1[l]);
    s1.erase(v1[r]);
    s1.insert(req);

    v1.assign(s1.begin(), s1.end());

    auto it = find(v2.begin(), v2.end(), req);
    if(it != v2.end()) v2.erase(it);
    v2.push_back(val1);
    v2.push_back(val2);

    cout << v1.size() << endl;
    for(ll i=0; i<v1.size(); i++) cout << v1[i] << " ";
    cout << endl;

    cout << v2.size() << endl;
    for(ll i=0; i<v2.size(); i++) cout << v2[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    twoSets(n);
    return 0;
}