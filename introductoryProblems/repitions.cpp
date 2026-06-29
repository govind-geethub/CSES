#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll repitions(string s)
{
    ll len = 1;
    ll maxLen = 1;
    for(ll i=1; i<s.length(); i++)
    {
        if(s[i] == s[i-1])
        {
            len++;
            maxLen = max(maxLen, len);
        }
        else len = 1;
    }
    return maxLen;
}

int main()
{
    string s;
    cin >> s;

    cout << repitions(s) << endl;
    return 0;
}