#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    while(n > 1)
    {
        fact *= n;
        n--;
    }
    return fact;
}

void createStrings(string s)
{
    int len = s.length();

    vector<int> freq(26);
    for(char ch : s) freq[ch - 'a']++;

    int fact1 = factorial(len);
    for(int i=0; i<26; i++)
    {
        if(freq[i] > 1)
        {
            int fact = factorial(freq[i]);
            fact1 = fact1 / fact;
        }
    }

    cout << fact1 << endl;

    sort(s.begin(), s.end());
    cout << s << endl;
    while(next_permutation(s.begin(), s.end())) cout << s << endl;
}

int main()
{
    string s;
    cin >> s;

    createStrings(s);
    return 0;
}