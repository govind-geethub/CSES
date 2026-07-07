#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll digitQuery(ll k)
{
    ll digLen = 1;  // curr dig len
    ll start = 1;   // starting num
    ll count = 9;   // no of digLen digit

    // finding which digLen group query lies
    while(k > start + digLen*count - 1)
    {
        start = start + digLen * count;
        digLen++;
        count *= 10;
    }

    // calc first no. of that digLen
    ll first = 1;
    ll temp = digLen;
    while(temp > 1) 
    {
        first *= 10; 
        temp--;
    }

    // which no. to reach
    ll offset = (k - start) / digLen;
    ll target = first + offset;

    string numStr = to_string(target);
    ll digOffset = (k - start);
    ll numPos = digOffset % digLen; // 3 digLen will repeat 0 1 2 for every num
    return numStr[numPos] - '0';
}

int main()
{
    ll q;
    cin >> q;

    while(q--)
    {
        ll k;
        cin >> k;

        cout << digitQuery(k) << endl;
    }
    return 0;
}