#include<bits/stdc++.h>
using namespace std;
#define ll long long

// knight noves in (2 x 3) (3 x 2) rectangles
// (i - 1 ) x (i - 2) where it can be placed in 2 positions
// total attack positions 2 * 2 * (i - 1) * (i - 2)
// total postions = (i*i) C 2
void twoKnights(int n)
{
    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }

    // 1 to n traverse
    cout << 0 << endl;  // i = 1
    cout << 6 << endl;  // i = 2
    for(int i=3; i<=n; i++)
    {
        ll num = i * i;
        ll totalPosition = (ll) num;
        totalPosition = totalPosition * ((ll) (num-1));
        totalPosition = totalPosition / 2;

        ll attackPos = (ll) (i-1);
        attackPos = attackPos * ((ll) (i-2));
        attackPos = attackPos * 4;

        cout << totalPosition - attackPos << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    twoKnights(n);
    return 0;
}