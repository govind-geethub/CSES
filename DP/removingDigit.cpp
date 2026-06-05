#include<bits/stdc++.h>
using namespace std;

int removingDigits(int n)
{
    int dp[n+1];
    dp[0]=0;    // base case

    for(int i=1; i<=n; i++)
    {
        int temp=i; // calculate minSteps to go i -> 0
        int minSteps=1e6+7;
        while(temp!=0)
        {
            int di=temp%10;
            temp=temp/10;

            if(di == 0) continue;   // no yield from digit 0
            minSteps=min(minSteps, 1+dp[i-di]);
        }
        dp[i]=minSteps;
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << removingDigits(n) << endl;
    return 0;
}

// without DP

// #include<bits/stdc++.h>
// using namespace std;

// int removingDigits(int n)
// {
//     int count=0;
//     while(n!=0)
//     {
//         string s=to_string(n);
//         char c='0';
//         for(int i=0; i<s.length(); i++)
//         {
//             if(c<s[i]) c=s[i];
//         }

//         int maxi=c-'0';
//         n=n-maxi;
//         count++;
//     }

//     return count;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     cout << removingDigits(n) << endl;
//     return 0;
// }

