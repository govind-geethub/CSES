#include<bits/stdc++.h>
using namespace std;

string palindromeReader(string s)
{
    vector<int> freq(26);
    for(char ch : s) freq[ch - 'A']++;

    int oddFreq = 0;
    char ch;
    for(int i=0; i<26; i++)
    {
        if(freq[i] % 2) 
        {
            oddFreq++;
            ch = i + 'A';
        }
    }

    if(oddFreq > 1) return "NO SOLUTION";

    string ans = "";
    for(int i=0; i<26; i++)
    {
        if(freq[i] % 2 == 0)
        {
            char ch = (i + 'A');
            string temp(freq[i]/2, ch);
            ans += temp;
        }
    }

    string ans1 = ans;
    reverse(ans1.begin(), ans1.end());

    if(oddFreq) 
    {
        string temp(freq[ch - 'A'], ch);
        ans += temp;
    }

    ans += ans1;
    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << palindromeReader(s) << endl;
    return 0;
}